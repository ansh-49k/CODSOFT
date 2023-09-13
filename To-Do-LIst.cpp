#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "****** To-Do List Manager ******" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Quit" << endl;
    cout << "**************************" << endl;
    cout << "Enter your choice: ";
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, description);

    Task newTask = {description, false};
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "===== Task List =====" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        if (tasks[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
    cout << "======================" << endl;
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, int index) {
    if (index >= 0 && static_cast<size_t>(index) < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks, int index) {
    if (index >= 0 && static_cast<size_t>(index) < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                int markIndex;
                cout << "Enter the task index to mark as completed: ";
                cin >> markIndex;
                markTaskCompleted(tasks, markIndex - 1); // Adjust for 0-based index
                break;
            case 4:
                int removeIndex;
                cout << "Enter the task index to remove: ";
                cin >> removeIndex;
                removeTask(tasks, removeIndex - 1); // Adjust for 0-based index
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
