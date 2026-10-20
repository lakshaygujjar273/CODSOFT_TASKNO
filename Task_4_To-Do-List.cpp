#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

// Clear invalid input from cin
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Add a new task to the list
void addTask() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush leftover newline
    cout << "\nEnter task description: ";
    string desc;
    getline(cin, desc);

    if (desc.empty()) {
        cout << "Task description cannot be empty.\n";
        return;
    }

    Task newTask;
    newTask.description = desc;
    newTask.completed = false;
    tasks.push_back(newTask);

    cout << "Task added successfully!\n";
}

// Display all tasks with their status
void viewTasks() {
    cout << "\n----- TO-DO LIST -----\n";
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". [" << (tasks[i].completed ? "Completed" : "Pending") << "] "
             << tasks[i].description << "\n";
    }
}

// Mark a task as completed
void markTaskCompleted() {
    viewTasks();
    if (tasks.empty()) return;

    cout << "\nEnter task number to mark as completed: ";
    int index;
    if (!(cin >> index)) {
        cout << "Invalid input.\n";
        clearInput();
        return;
    }

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].completed = true;
    cout << "Task marked as completed!\n";
}

// Remove a task from the list
void removeTask() {
    viewTasks();
    if (tasks.empty()) return;

    cout << "\nEnter task number to remove: ";
    int index;
    if (!(cin >> index)) {
        cout << "Invalid input.\n";
        clearInput();
        return;
    }

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + (index - 1));
    cout << "Task removed successfully!\n";
}

// Display the menu options
void showMenu() {
    cout << "\n===== TO-DO LIST MANAGER =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;

    while (true) {
        showMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option (1-5).\n";
        }
    }

    return 0;
}