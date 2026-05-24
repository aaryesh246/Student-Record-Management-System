# Student Record Management

This project is a simple C-based student record management system. It uses a binary search tree or linked list structure to store student data and provides a console menu for adding, deleting, searching, and displaying student records.

## Project Contents

- `main.c` - The application entry point and menu-driven interface.
- `student.c` - Student record operations such as adding, deleting, searching, and displaying students.
- `student.h` - Declarations for student management functions.
- `bst.c` / `bst.h` - Binary search tree implementation for student data storage and traversal.
- `Linked_list.c` / `LL.h` - Linked list helper definitions and node structures used by student and tree logic.
- `new.c` - Additional or experimental code (not required for the main menu flow).
- `a.exe`, `program.exe`, `ss.exe` - Compiled binaries or test executables (not source files).

## Features

- Add a student with name, ID, and CGPA.
- Delete a student record by position.
- Search for a student by name.
- Display all stored student records.

## Build and Run

Use a C compiler such as `gcc` to compile the project:

```bash
gcc main.c student.c bst.c Linked_list.c -o student_management
```

Then run the executable:

```bash
./student_management
```

## Notes

- Input is read from the console.
- The project currently uses a simple in-memory data structure and does not persist records to disk.
- Deleting students is based on position rather than a unique ID.
