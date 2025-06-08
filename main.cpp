#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdexcept>
#include <limits>
#ifdef _WIN32
  #include <windows.h>
  #include <conio.h>
#else
  #include <unistd.h>
  #include <termios.h>
#endif

// -----------------------------
// Cross-platform helpers
// -----------------------------
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void waitKey() {
#ifdef _WIN32
    _getch();
#else
    struct termios oldt, newt;
    tcgetattr(0, &oldt);
    newt = oldt; newt.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &newt);
    getchar();
    tcsetattr(0, TCSANOW, &oldt);
#endif
}

// -----------------------------
// Console colors (bright only)
// -----------------------------
enum Color : int {
    RESET   = 7,
    CYAN    = 11,
    GREEN   = 10,
    YELLOW  = 14,
    MAGENTA = 13,
    WHITE   = 15,
    RED     = 12
};
void setColor(Color c) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
#else
    static const char* codes[] = {
        "\033[0m",      // 0
        /*1-6*/ "", "", "", "", "", "",
        "\033[97m",     // 7 WHITE
        "", "", "",
        "\033[36m",     // 11 CYAN
        "\033[32m",     // 12 GREEN
        "\033[31m",     // 13 MAGENTA
        "\033[33m",     // 14 YELLOW
        "\033[37m"      // 15
    };
    std::cout << codes[c];
#endif
}

// -----------------------------
// Simple file-based logger
// -----------------------------
class Logger {
public:
    static Logger& instance() {
        static Logger inst("program.log");
        return inst;
    }
    void log(const std::string& level, const std::string& msg) {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream ts;
        ts << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        logfile_ << ts.str() << " [" << level << "] " << msg << "\n";
    }
private:
    std::ofstream logfile_;
    Logger(const std::string& fname) : logfile_(fname, std::ios::app) {
        if (!logfile_) throw std::runtime_error("Cannot open log file");
    }
    ~Logger() { logfile_.close(); }
    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;
};

// -----------------------------
// Student record + CSV manager
// -----------------------------
struct Student { int index; std::string first, last; };
class StudentManager {
    const std::string file_ = "students.csv";
public:
    std::vector<Student> load() {
        std::vector<Student> v;
        std::ifstream in(file_);
        std::string line;
        while (std::getline(in, line)) {
            std::istringstream iss(line);
            std::string tok;
            Student s;
            if (std::getline(iss, tok, ',')) {
                try { s.index = std::stoi(tok); }
                catch(...) { continue; }
                if (std::getline(iss, s.first, ',') && std::getline(iss, s.last)) {
                    v.push_back(s);
                }
            }
        }
        return v;
    }
    void save(const Student& s) {
        std::ofstream out(file_, std::ios::app);
        out << s.index << ',' << s.first << ',' << s.last << '\n';
        out.flush();
    }
};

// -----------------------------
// Header & menu
// -----------------------------
void printHeader() {
    setColor(CYAN);
    std::cout << R"(
**********************************************
*         STUDENT MANAGEMENT SYSTEM          *
**********************************************
)";
    setColor(WHITE);
    std::cout << " Author: Adrian Lesniak\n"
                 " Manage student records & simple tools\n"
                 "----------------------------------------\n";
}
void printMenu() {
    setColor(MAGENTA);
    std::cout <<
        "1) Manage Students\n"
        "2) Trapezoid Area\n"
        "3) Function Eval\n"
        "4) Random Numbers\n"
        "5) Temp Converter\n"
        "0) Exit\n";
    setColor(WHITE);
}

// -----------------------------
// Validated numeric input
// -----------------------------
template<typename T>
T getValidated(const std::string& prompt, T lo, T hi) {
    T val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val && val >= lo && val <= hi) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return val;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        setColor(RED);
        std::cout << "  ! Invalid input, try again.\n";
        setColor(WHITE);
        Logger::instance().log("ERROR","Invalid numeric input");
    }
}

// -----------------------------
// Task 1: Student management
// -----------------------------
void task1_manageStudents() {
    clearScreen(); printHeader();
    setColor(YELLOW);
    std::cout << "a) Add new student\n"
                 "   Enter index, first & last name.\n"
                 ;
    setColor(WHITE);
    std::cout << "b) List all students\n"
                 "   Shows all saved records.\n";
    setColor(WHITE);  // prompt in white
    std::cout << "Choice [a/b]: ";
    char c; std::cin >> c; std::cin.ignore(1,'\n');

    StudentManager mgr;
    if (c=='a'||c=='A') {
        Student s;
        s.index = getValidated<int>(" Index no (1-9999999): ",1,9999999);
        std::cout<<" First name: "; std::getline(std::cin,s.first);
        std::cout<<" Last  name: "; std::getline(std::cin,s.last);
        mgr.save(s);
        setColor(GREEN);
        std::cout<<" -> Student saved!\n";
        setColor(WHITE);
        Logger::instance().log("INFO","Added student "+ std::to_string(s.index));
    }
    else {
        setColor(YELLOW);
        std::cout<<" Listing all students:\n\n";
        setColor(WHITE);
        auto v = mgr.load();
        if (v.empty()) {
            std::cout<<" (none found)\n";
        } else {
            std::cout<<"#   First      Last\n";
            std::cout<<"--------------------------\n";
            for (auto& s: v) {
                std::cout<< std::setw(3)<<s.index<<"  "
                         << std::setw(10)<<s.first<<"  "
                         << s.last<<"\n";
            }
        }
    }
}

// -----------------------------
// Task 2: Trapezoid area
// -----------------------------
void task2_trapezoid() {
    clearScreen(); printHeader();
    setColor(YELLOW);
    std::cout<<" Compute area of a trapezoid: (a+b)/2 * h\n";
    setColor(WHITE);
    double a = getValidated<double>(" Base a (>0): ",1e-6,1e6);
    double b = getValidated<double>(" Base b (>0): ",1e-6,1e6);
    double h = getValidated<double>(" Height h (>0): ",1e-6,1e6);
    double area = (a+b)/2*h;
    setColor(GREEN);
    std::cout<<"\n Area = "<<std::fixed<<std::setprecision(2)<<area<<"\n";
    setColor(WHITE);
    Logger::instance().log("INFO","Trapezoid area="+std::to_string(area));
}

// -----------------------------
// Task 3: Function evaluation
// -----------------------------
void task3_function() {
    clearScreen(); printHeader();
    setColor(YELLOW);
    std::cout<<" Evaluate y = 2*x+1  if -1<=x<=20, else y=2/x\n";
    setColor(WHITE);
    double x = getValidated<double>(" x value: ",-1e6,1e6);
    double y = (x>=-1 && x<=20) ? (2*x+1) : (2.0/x);
    setColor(GREEN);
    std::cout<<"\n y = "<<y<<"\n";
    setColor(WHITE);
    Logger::instance().log("INFO","Function y="+std::to_string(y));
}

// -----------------------------
// Task 4: Random numbers
// -----------------------------
void task4_random() {
    clearScreen(); printHeader();
    setColor(YELLOW);
    std::cout<<" Generate ten random numbers 1..10\n\n";
    setColor(WHITE);
    srand((unsigned)time(nullptr));
    for (int i=0;i<10;i++) std::cout<<(rand()%10+1)<<" ";
    std::cout<<"\n";
    Logger::instance().log("INFO","Generated random numbers");
}

// -----------------------------
// Task 5: Temperature converter
// -----------------------------
void task5_temp() {
    clearScreen(); printHeader();
    setColor(YELLOW);
    std::cout<<" Convert temperature: C->F or F->C\n";
    std::cout<<" 1) C->F    2) F->C\n";
    setColor(WHITE);
    int c = getValidated<int>(" Choice: ",1,2);
    double t = getValidated<double>(" Temperature: ", -273.15,1e4);
    double r = (c==1) ? (t*9.0/5.0+32.0) : ((t-32.0)*5.0/9.0);
    setColor(GREEN);
    std::cout<<"\n Result: "<<std::fixed<<std::setprecision(2)<<r<<"\n";
    setColor(WHITE);
    Logger::instance().log("INFO","Temp convert result="+std::to_string(r));
}

// -----------------------------
// Main
// -----------------------------
int main(){
    try {
        while (true) {
            clearScreen(); printHeader(); printMenu();
            int choice = getValidated<int>("\n Your choice (0-5): ",0,5);
            if (choice==0) break;
            switch(choice) {
                case 1: task1_manageStudents(); break;
                case 2: task2_trapezoid();        break;
                case 3: task3_function();         break;
                case 4: task4_random();           break;
                case 5: task5_temp();             break;
            }
            waitKey();
        }
    } catch(const std::exception& ex) {
        setColor(RED);
        std::cerr<<"Fatal: "<<ex.what()<<"\n";
        setColor(WHITE);
        Logger::instance().log("ERROR",ex.what());
        return 1;
    }
    return 0;
}
