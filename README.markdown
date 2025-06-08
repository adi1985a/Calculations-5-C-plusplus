# 🛠️🎓 Student & Utility Toolkit Pro ⚙️
_A C++ console application offering a suite of tools for student data entry, geometric calculations, function evaluation, random number generation, and temperature conversion._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features & Tools](#-key-features--tools)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Setup](#️-installation-and-setup)
6.  [Usage Guide](#️-usage-guide)
7.  [File Structure & Data Persistence](#-file-structure--data-persistence)
8.  [Technical Notes](#-technical-notes)
9.  [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**Student & Utility Toolkit Pro**, developed by Adrian Lesniak, is a versatile C++ console application that provides a collection of useful tools through a clear, menu-driven interface. It includes functionalities for: basic student data entry and display; calculating the area of a trapezoid with input validation; evaluating a piecewise mathematical function; generating a series of random numbers; and converting temperatures between Celsius and Fahrenheit. The program enhances user experience with a colorful console output (Windows-specific), logs operational errors to `error_log.txt`, and saves results from the trapezoid area calculator to `calculations.txt`.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features & Tools

The application offers a suite of distinct tools accessible via a main menu:

1.  🧑‍🎓 **Student Data Management**:
    *   Allows input of a student's name, surname, and index number.
    *   Displays the entered student data.
2.  📐 **Trapezoid Area Calculator**:
    *   Prompts for the lengths of the two bases and the height of a trapezoid.
    *   Calculates the area using the formula: Area = ((base1 + base2) / 2) * height.
    *   Includes input validation to ensure all dimensions are positive.
    *   Saves the calculated area and input dimensions to `calculations.txt`.
3.  📉 **Function Calculator**:
    *   Evaluates a piecewise function:
        *   `y = 2x + 1` if `x` is in the range [-1, 20].
        *   `y = 2 / x` if `x` is outside the range [-1, 20] (and x ≠ 0).
    *   Prompts the user for a value of `x`.
4.  🎲 **Random Number Generator**:
    *   Generates and displays a sequence of random numbers (e.g., 10 numbers) within a predefined range (e.g., [1, 10]).
5.  🌡️ **Temperature Converter**:
    *   Allows conversion from Celsius to Fahrenheit: °F = (°C × 9/5) + 32.
    *   Allows conversion from Fahrenheit to Celsius: °C = (°F - 32) × 5/9.
    *   Prompts the user for the temperature value and the direction of conversion.

### Common Features:
*   🖥️ **Interactive Console Interface**:
    *   `printHeader`: Displays an ASCII art logo and a description of the program.
    *   `printMenu`: Shows a numbered list of available tools and an exit option.
    *   **Colorful Output**: Utilizes Windows console API (`SetConsoleTextAttribute`) for distinct colors (yellow, cyan, green, white, red) to improve UI clarity.
*   ✍️ **Error Handling & Logging**:
    *   `logError`: A dedicated function to log any operational errors with timestamps to `error_log.txt`.
    *   Input validation is present, particularly for the trapezoid calculator.
*   ⚙️ **Clean UI Flow**: Clears the screen between tasks for a less cluttered user experience.

## 🖼️ Screenshots

_Screenshots showcasing the main menu with ASCII logo, inputs and outputs for each of the five tools, and examples from `error_log.txt` and `calculations.txt`._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
  <img src="screenshots\7.jpg" width="300"/>
  <img src="screenshots\8.jpg" width="300"/>
  <img src="screenshots\9.jpg" width="300"/>
</p>


## ⚙️ System Requirements

*   **Operating System**: Windows (due to dependencies like `<windows.h>` for `SetConsoleTextAttribute` and `<conio.h>` for `_getch`).
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<string>`, `<vector>` (if used), `<math.h>` or `<cmath>`, `<cstdlib>`, `<ctime>`, `<fstream>`, `<iomanip>`, `<limits>`.
*   **Write Permissions**: The application needs write permissions in its execution directory to create/modify `error_log.txt` and `calculations.txt`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Save Main Code**:
    Ensure your main program logic (including all tool implementations, UI functions, logging, and `main()`) is saved as `student_system.cpp` (or your chosen main file name) in the project directory. *(The description implies a single-file structure for the core logic, with utility functions potentially inlined or also within this file if no separate `utils.h` is mandated by the actual code for this project).*

3.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, etc.) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ student_system.cpp -o student_system.exe -std=c++11 -static-libgcc -static-libstdc++
    ```
    *(Adjust if you have separate utility `.cpp` files that need to be compiled and linked).*

4.  **Run the Program**:
    ```bash
    .\student_system.exe
    ```
    (or `student_system.exe` in CMD)

## 💡 Usage Guide

1.  Compile and run `student_system.exe` as detailed above.
2.  **Interface**:
    *   The program will first display a header with an ASCII logo and a program description.
    *   A menu will then appear with the following options:
        1.  Student Data Management
        2.  Trapezoid Area Calculator
        3.  Function Calculator
        4.  Random Number Generator
        5.  Temperature Converter
        0.  Exit
3.  **Input**:
    *   Select a menu option (0–5) by typing the number and pressing Enter.
    *   Based on the selected tool, you will be prompted for specific inputs:
        *   **Student Data**: Name, surname, index number.
        *   **Trapezoid Area**: Lengths of the two parallel sides (bases) and the height.
        *   **Function Calculator**: A value for `x`.
        *   **Random Number Generator**: Typically runs automatically or asks for the quantity of numbers.
        *   **Temperature Converter**: The temperature value and the original unit (Celsius or Fahrenheit).
    *   Invalid inputs (e.g., negative dimensions for the trapezoid, non-numeric input where numbers are expected) will trigger an error message (logged to `error_log.txt`) and may prompt for re-entry.
4.  **Output**:
    *   **Student Data**: Displays the entered information (e.g., "Student's name: John Doe, Index: 12345").
    *   **Trapezoid Area**: Shows the calculated area (e.g., "The area of the trapezoid is: 25.00 square units"). This result is also saved to `calculations.txt`.
    *   **Function Value**: Displays the computed value of `y` for the given `x` (e.g., "For x = 5, y(x) = 2*x+1 = 11.00").
    *   **Random Numbers**: Lists the generated random numbers (e.g., "Generated numbers: 7 3 9 1 5 ...").
    *   **Temperature Conversion**: Shows the converted temperature (e.g., "32.0 Celsius is 89.6 Fahrenheit").
    *   Errors are logged to `error_log.txt`.
5.  **Actions**:
    *   After each tool finishes its operation and displays results, you will typically be prompted to press any key to return to the main menu.
    *   Select option `0` from the main menu to exit the application.

## 🗂️ File Structure & Data Persistence

*   `student_system.cpp`: The main C++ source file containing all program logic, including the implementations for each tool, UI management, and error logging.
*   `error_log.txt`: A plain text file where error messages are recorded with timestamps. This file is created or appended to.
*   `calculations.txt`: A plain text file that stores a record of results from the Trapezoid Area Calculator (and potentially other tools if extended), likely including input parameters and the computed result with a timestamp. This file is created or appended to.
*   `README.md`: This documentation file.

## 📝 Technical Notes

*   **Windows Specifics**: The project heavily relies on Windows-specific headers (`<windows.h>`, `<conio.h>`) for functionalities like colored console output (`SetConsoleTextAttribute`) and direct keypress input (`_getch()`). Adapting for true cross-platform compatibility would require using ANSI escape codes for colors and alternative methods for non-buffered input or screen clearing on Unix-like systems.
*   **Random Number Generator Seed**: The description notes a potential lack of `srand(time(0))` initialization for the random number generator. If not present, `rand()` will produce the same sequence of numbers each time the program runs. Adding `srand(time(NULL));` (or `srand(static_cast<unsigned int>(time(0)));`) once at the beginning of `main()` is crucial for varied random numbers.
*   **Input Validation**: While the trapezoid calculator has validation for positive inputs, it's noted that other tools might assume valid input. Enhancing input validation across all tools would improve robustness.
*   **Potential Enhancements**: The program could be extended by adding persistent storage for student data, implementing more calculation tools, improving cross-platform support, adding more sophisticated error logging, or developing a graphical user interface (GUI).

## 🤝 Contributing

Contributions to **Student & Utility Toolkit Pro** are highly encouraged! If you have ideas for adding new tools, improving existing functionalities, enhancing cross-platform compatibility, or refining the user interface:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourUtilityIdea`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourUtilityIdea'`).
4.  Push to the branch (`git push origin feature/YourUtilityIdea`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
🛠️ _A versatile toolkit for everyday calculations and data management!_
