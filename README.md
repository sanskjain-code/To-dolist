# To-dolist

# To-Do List Manager

A simple command-line to-do list application written in C++. Manage your tasks efficiently with features to add, view, complete, and delete tasks. All tasks are automatically saved to a file for persistence.

## Features

- ✅ Add new tasks
- 📋 View all tasks with completion status
- ✔️ Mark tasks as complete
- 🗑️ Delete tasks
- 💾 Auto-save to file

## Installation

**Compile:**
```bash
g++ -o todolist todolist.cpp
```

**Run:**
```bash
./todolist
```

## Usage

The program presents a simple menu:
```
1. Add Task
2. View Tasks
3. Mark Task as Complete
4. Delete Task
5. Save and Exit
```

Simply enter the number of your choice and follow the prompts.

## How It Works

- Tasks are stored in a `tasks.txt` file
- The file is automatically loaded when you start the program
- All changes are saved when you exit

## Learning Concepts

This project demonstrates:
- Vectors for dynamic arrays
- Structs for data organization
- File I/O operations
- Input validation
- Menu-driven program flow

## Requirements

- C++ compiler (g++, MinGW, or similar)
- Basic command-line knowledge

---

Perfect for beginners learning C++ programming!
