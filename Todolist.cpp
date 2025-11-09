#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool isCompleted;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskComplete(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void saveTasks(const vector<Task>& tasks);
void loadTasks(vector<Task>& tasks);
void clearInputBuffer();

int main() {
    vector<Task> tasks;
    int choice;
    
    // Load existing tasks from file
    loadTasks(tasks);
    
    cout << "=== Welcome to Simple To-Do List Manager ===" << endl;
    
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Input validation
        if (cin.fail()) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskComplete(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                saveTasks(tasks);
                cout << "Tasks saved! Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}

void displayMenu() {
    cout << "\n--- Main Menu ---" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Complete" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Save and Exit" << endl;
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "\nEnter task description: ";
    getline(cin, newTask.description);
    newTask.isCompleted = false;
    
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks in your list!" << endl;
        return;
    }
    
    cout << "\n=== Your Tasks ===" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". ";
        if (tasks[i].isCompleted) {
            cout << "[✓] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
}

void markTaskComplete(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks to mark complete!" << endl;
        return;
    }
    
    viewTasks(tasks);
    
    int taskNum;
    cout << "\nEnter task number to mark as complete: ";
    cin >> taskNum;
    
    if (cin.fail() || taskNum < 1 || taskNum > static_cast<int>(tasks.size())) {
        clearInputBuffer();
        cout << "Invalid task number!" << endl;
        return;
    }
    
    clearInputBuffer();
    tasks[taskNum - 1].isCompleted = true;
    cout << "Task marked as complete!" << endl;
}

void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks to delete!" << endl;
        return;
    }
    
    viewTasks(tasks);
    
    int taskNum;
    cout << "\nEnter task number to delete: ";
    cin >> taskNum;
    
    if (cin.fail() || taskNum < 1 || taskNum > static_cast<int>(tasks.size())) {
        clearInputBuffer();
        cout << "Invalid task number!" << endl;
        return;
    }
    
    clearInputBuffer();
    tasks.erase(tasks.begin() + taskNum - 1);
    cout << "Task deleted successfully!" << endl;
}

void saveTasks(const vector<Task>& tasks) {
    ofstream file("tasks.txt");
    
    if (!file.is_open()) {
        cout << "Error saving tasks!" << endl;
        return;
    }
    
    for (const auto& task : tasks) {
        file << task.isCompleted << endl;
        file << task.description << endl;
    }
    
    file.close();
}

void loadTasks(vector<Task>& tasks) {
    ifstream file("tasks.txt");
    
    if (!file.is_open()) {
        return; // File doesn't exist yet, no tasks to load
    }
    
    Task task;
    while (file >> task.isCompleted) {
        file.ignore(); // Ignore newline after boolean
        getline(file, task.description);
        tasks.push_back(task);
    }
    
    file.close();
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}