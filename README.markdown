# Student Management System

## Overview
This C++ console application, authored by Adrian Lesniak, provides a menu-driven interface for student-related tools: student data entry, trapezoid area calculation, function evaluation, random number generation, and temperature conversion. It features colored console output, error logging to `error_log.txt`, result saving to `calculations.txt`, and input validation.

## Features
- **Tools**:
  - **Student Data Management**: Inputs and displays student name, surname, and index number.
  - **Trapezoid Area Calculator**: Computes area with input validation; saves results.
  - **Function Calculator**: Evaluates `y=2x+1` for x in [-1, 20], else `y=2/x`.
  - **Random Number Generator**: Generates numbers in range [1, 10].
  - **Temperature Converter**: Converts Celsius to Fahrenheit or vice versa.
- **Interface**:
  - `printHeader`: Displays ASCII art logo and program description.
  - `printMenu`: Shows options 1–5 and 0 to exit.
  - Colored output (yellow, cyan, green, white, red) using Windows console API.
- **Error Handling**:
  - `logError`: Logs errors with timestamps to `error_log.txt`.
  - Validates trapezoid inputs (positive dimensions).
- **File I/O**:
  - Saves trapezoid area results to `calculations.txt`.
  - Logs errors to `error_log.txt`.
- **Main Program**:
  - Loops until user selects exit (0).
  - Clears screen between tasks for clean UI.

## Requirements
- C++ compiler (e.g., g++, MSVC) with C++11 or later
- Windows OS (for `<windows.h>`, `SetConsoleTextAttribute`, `_getch`)
- Standard C++ libraries: `<iostream>`, `<string>`, `<math.h>`, `<cstdlib>`, `<ctime>`, `<fstream>`, `<windows.h>`, `<iomanip>`, `<conio.h>`
- Operating system: Windows (due to console functions)
- Write permissions for `error_log.txt` and `calculations.txt`

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Save the provided code as `student_system.cpp`.
3. Compile the program:
   ```bash
   g++ student_system.cpp -o student_system
   ```
4. Run the program:
   ```bash
   .\student_system
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays header with ASCII logo and program description.
   - Shows menu with options:
     1. Student Data Management
     2. Trapezoid Area Calculator
     3. Function Calculator
     4. Random Number Generator
     5. Temperature Converter
     0. Exit
3. **Input**:
   - Select 0–5 to choose a tool.
   - Provide inputs (e.g., student data, trapezoid dimensions, temperature).
   - Invalid inputs (e.g., negative trapezoid dimensions) trigger errors.
4. **Output**:
   - Student Data: Shows name, surname, index (e.g., "Student's name: John").
   - Trapezoid: Area (e.g., "The area of the trapezoid is: 25.00").
   - Function: y value (e.g., "y(x)=2*x+1 for x=5 is: 11").
   - Random Numbers: List of numbers (e.g., "7 3 9 ...").
   - Temperature: Converted value (e.g., "The temperature in Fahrenheit is: 98.6").
   - Errors logged to `error_log.txt`.
5. **Actions**:
   - Press any key to return to menu after each task.
   - Select 0 to exit.

## File Structure
- `student_system.cpp`: Main C++ source file with program logic.
- `error_log.txt`: Log file for errors (created/appended).
- `calculations.txt`: Output file for trapezoid area results (created/appended).
- `README.md`: This file, providing project documentation.

## Notes
- Windows-specific due to `<windows.h>`, `_getch`, and console color functions; adapt for other OS (e.g., ANSI colors, `system("clear")`).
- Random number generator lacks seed initialization (`srand`), leading to repetitive sequences; add `srand(time(0))` in `main`.
- Trapezoid calculator validates positive inputs; other tools assume valid input.
- Extend by adding data storage, more calculations, or cross-platform support.
- Ensure write permissions for `error_log.txt` and `calculations.txt`.
- No external dependencies beyond standard C++ libraries.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.