## AMIT-C Programming Project - Student Database Management

This project involves the creation of a simple student database management system using C programming. The system utilizes modular programming concepts to achieve functionality. The project consists of three main files: `STD.h`, `SDB.h`, and `SDBAPP.c`. Additionally, there are implementations in `SDB.c` and `main.c`.

### STD.h

Defines various data types such as `uint8`, `Int8`, `uint16`, `int16`, `uint32`, `int32`, and `bool` (`enum {false, true}`). These data types are used throughout the project to enhance code readability and portability.

### SDB.h

Declares the functions and structures required for the student database management system. It includes a structure `student` with fields for student details such as ID, year, course IDs, and grades.

### SDB.c

This file contains the implementations of functions related to the student database management system:

- `SDB_IsFull()`: Checks if the database is full.
- `SDB_GetUsedSize()`: Retrieves the number of students in the database.
- `SDB_AddEntry()`: Adds a new student entry to the database.
- `SDB_DeleteEntry(uint32 id)`: Deletes a student entry based on the given ID.
- `SDB_ReadEntry(uint32 id)`: Reads and displays student data based on the given ID.
- `SDB_GetList(uint8 * count, uint32 * list)`: Retrieves a list of all student IDs.
- `SDB_IsIdExist(uint32 id)`: Checks if a given ID exists in the database.

### SDBAPP.c

This file houses the main application loop for user interaction. It provides a menu-driven interface for the user to perform various actions on the student database, such as adding entries, reading data, deleting entries, and more. The `SDB_APP()` function handles user input and calls the corresponding functions based on the user's choice.

### main.c

In this file, the program starts by calling `SDB_APP()`, which initiates the main loop of the application and facilitates user interaction through the menu.

### Additional Notes

- The project adheres to modular programming principles, improving code organization and maintainability.
- Each function's purpose is clearly documented through comments, explaining its role and expected behavior.
- The code maintains a student counter and an array of structures (`studentArray`) to manage the student data.
- Proper error handling and user feedback are implemented to ensure smooth user experience.

**Note:** The provided content is a summary of the project's structure, purpose, and main components. To see the full details and implementation, refer to the actual code files in your project. Additionally, consider creating the required header files (`STD.h` and `SDB.h`) and ensuring that the code is well-documented and follows best practices.

To fully understand the project, refer to the actual code files in your project directory. Detailed explanations and implementation decisions can be found within the code comments. For a visual demonstration, consider creating a [screen-recorded-video](https://github.com/Yusuf-Elsayed/AMIT-C_Programming_Project/tree/main/Screen%20recorded%20Video) showcasing the project's functionalities and explaining the rationale behind your implementation choices.
