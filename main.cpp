#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

// Function prototypes
void setConsoleColor(int);
void printHeader();
void logError(const string&);
void printMenu();
void zadanie1(), zadanie2(), zadanie3(), zadanie4(), zadanie5();
bool validateInput(double, double, double);

// ASCII Art and UI functions
void printHeader() {
    setConsoleColor(14); // Yellow
    cout << R"(
    +--------------------------------+
    |     Student Management System   |
    +--------------------------------+
    )" << endl;
    
    setConsoleColor(15); // Bright White
    cout << "\nAuthor: Adrian Lesniak" << endl;
    cout << "Program Description:" << endl;
    cout << "This program provides various student-related tools including:" << endl;
    cout << "- Student data management" << endl;
    cout << "- Geometric calculations (trapezoid area)" << endl;
    cout << "- Mathematical function evaluation" << endl;
    cout << "- Random number generation" << endl;
    cout << "- Temperature conversion utilities" << endl;
    cout << "\n----------------------------------------" << endl;
    setConsoleColor(7); // White
}

void printMenu() {
    cout << "\nAvailable tasks:\n";
    setConsoleColor(11); // Light Cyan
    cout << "1. Student Data Management\n";
    cout << "2. Trapezoid Area Calculator\n";
    cout << "3. Function Calculator\n";
    cout << "4. Random Number Generator\n";
    cout << "5. Temperature Converter\n";
    setConsoleColor(7); // White
}

// Color handling
void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Error logging
void logError(const string& error) {
    ofstream logFile("error_log.txt", ios::app);
    time_t now = time(0);
    string dateTime = ctime(&now);
    logFile << dateTime.substr(0, dateTime.length()-1) << ": " << error << endl;
    logFile.close();
}

int main() {
    SetConsoleTitle("Student Management System");
    string koniec1;
    int choice;
    
    while(true) {
        system("cls");
        printHeader();
        printMenu();
        
        setConsoleColor(14);
        cout << "\nEnter your choice (1-5) or 0 to exit: ";
        setConsoleColor(7);
        cin >> choice;
        
        switch(choice) {
            case 0:
                return 0;
            case 1:
                system("cls");
                cout << "Task no.5.1 - Student data." << endl;
                zadanie1();
                cout << "\nPress any key to return to menu...";
                _getch();
                break;
            case 2:
                system("cls");
                cout << "Task no.5.2 - Trapezoid field." << endl;
                zadanie2();
                cout << "\nPress any key to return to menu...";
                _getch();
                break;
            case 3:
                system("cls");
                cout << "Task no.5.3 - Function." << endl;
                zadanie3();
                cout << "\nPress any key to return to menu...";
                _getch();
                break;
            case 4:
                system("cls");
                cout << "Task no.5.4 - Draw numbers from the range." << endl;
                zadanie4();
                cout << "\nPress any key to return to menu...";
                _getch();
                break;
            case 5:
                system("cls");
                cout << "Task no.5.5 - Temperature conversion." << endl;
                zadanie5();
                cout << "\nPress any key to return to menu...";
                _getch();
                break;
            default:
                setConsoleColor(12);
                cout << "\nInvalid choice! Press any key to try again...";
                setConsoleColor(7);
                _getch();
                break;
        }
    }

    return 0;
}

void zadanie1() {
    setConsoleColor(11);
    cout << "\n=== Student Data Entry ===\n";
    setConsoleColor(7);
    
    string imie, nazwisko; // string data
    int nr_indeksu;

    cout << "\nEnter the name of the student: ";
    cin >> imie;

    cout << "Enter the surname of the student: ";
    cin >> nazwisko;

    cout << "Enter the student's index number: ";
    cin >> nr_indeksu;

    cout << "\nSUMMARY: " << endl;
    cout << "Student's name: " << imie << endl;
    cout << "Student's surname: " << nazwisko << endl;
    cout << "Student index number: " << nr_indeksu << endl;

    cout << endl;
}

void zadanie2() {
    setConsoleColor(11);
    cout << "\n=== Trapezoid Calculator ===\n";
    setConsoleColor(7);
    
    float a, b, h;
    try {
        cout << "\nEnter the length of the base a: ";
        cin >> a;
        cout << "Enter the length of the base b: ";
        cin >> b;
        cout << "Enter the height of the trapezoid: ";
        cin >> h;

        if (!validateInput(a, b, h)) {
            throw runtime_error("Invalid trapezoid dimensions");
        }

        double area = (a + b) / 2 * h;
        setConsoleColor(10); // Light Green
        cout << fixed << setprecision(2);
        cout << "\nThe area of the trapezoid is: " << area << endl;
        setConsoleColor(7);

        // Save to file
        ofstream outFile("calculations.txt", ios::app);
        outFile << "Trapezoid area calculation: " << area << endl;
        outFile.close();

    } catch (const exception& e) {
        logError(e.what());
        setConsoleColor(12);
        cout << "Error: " << e.what() << endl;
        setConsoleColor(7);
    }

    cout << endl;
}

// Input validation
bool validateInput(double a, double b, double h) {
    return (a > 0 && b > 0 && h > 0);
}

void zadanie3() {
    setConsoleColor(11);
    cout << "\n=== Function Calculator ===\n";
    setConsoleColor(7);
    
    double x = 0;

    if (x>=-1 && x<=20) { // condition1
        cout << "\nCalculate the value of the function y(x)=2*x+1\n";
        cout << "---------------------------------------\n";
        cout << "Enter the value of point x: ";
        cin >> x;
        cout << "Function value y(x)=2*x+1 for a point " << x << " is: " << (2 * x) + 1 <<endl;
    }

    if (x<-1 || x>20) { // condition2
        cout << "\nCalculate the value of the function y(x)=2/x\n";
        cout << "---------------------------------------\n";
        cout << "Enter the value of point x: ";
        cin >> x;
        cout << "Function value y(x)=2/x for a point " << x << " is: " << 2/x <<endl;
    }

    cout << endl;
}

void zadanie4() {
    setConsoleColor(11);
    cout << "\n=== Random Number Generator ===\n";
    setConsoleColor(7);
    
    int p=1,k=10;
    int wylosowana_liczba;

    for (int i = p; i <= k; i++) {
        wylosowana_liczba = rand() % (k - p + 1) + p;
        cout << wylosowana_liczba << endl;
    }

    cout << endl;
}

void zadanie5() {
    setConsoleColor(11);
    cout << "\n=== Temperature Converter ===\n";
    setConsoleColor(7);
    
    int wybor;
    string zmienna_sterujaca;

    cout<<"\nChoose what you want to convert."<<endl;
    cout<<"1.Celsius to Fahrenheit."<<endl;
    cout<<"2.Fahrenheit to Celsius"<<endl;
    cout<<"\nYour choice(enter number 1 or 2): ";
    cin>>wybor;

    switch(wybor) {
        case 1:
            float Tc;
            float Tf;

            cout<<"\nEnter the temperature in degrees Celsius: ";
            cin>>Tc;

            cout<<"The temperature in degrees Fahrenheit is: "<< (Tc * 9/5) + 32 <<endl;
            break;

        case 2:
            cout<<"\nEnter the temperature in degrees Fahrenheit: ";
            cin>>Tf;

            cout<<"The temperature in degrees Celsius is: "<< (Tf - 32) * 5/9 <<endl;
            break;

        default:
            cout<<"The entered data is incorrect. \n"<<endl;
            break;
    }

    cout << endl;
}

