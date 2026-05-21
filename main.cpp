#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Task {
public:
    string title;
    bool completed;

    Task(string t) {
        title = t;
        completed = false;
    }
};

vector<Task> tasks;

void saveTasks() {
    ofstream file("tasks.txt");

    for (int i = 0; i < tasks.size(); i++) {
        file << tasks[i].title << "," << tasks[i].completed << endl;
    }

    file.close();
}

void loadTasks() {
    ifstream file("tasks.txt");

    string title;
    bool completed;

    while (getline(file, title, ',')) {
        file >> completed;
        file.ignore();

        Task t(title);
        t.completed = completed;

        tasks.push_back(t);
    }

    file.close();
}

void addTask() {
    string title;

    cin.ignore();

    cout << "Enter task: ";
    getline(cin, title);

    Task t(title);

    tasks.push_back(t);

    saveTasks();

    cout << "Task added successfully!\n";
}

void viewTasks() {

    if (tasks.size() == 0) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n------ TASK LIST ------\n";

    for (int i = 0; i < tasks.size(); i++) {

        cout << i + 1 << ". ";

        if (tasks[i].completed)
            cout << "[Completed] ";
        else
            cout << "[Pending] ";

        cout << tasks[i].title << endl;
    }
}

void markCompleted() {

    int num;

    viewTasks();

    cout << "\nEnter task number to mark completed: ";
    cin >> num;

    if (num > 0 && num <= tasks.size()) {

        tasks[num - 1].completed = true;

        saveTasks();

        cout << "Task marked as completed!\n";
    }
    else {
        cout << "Invalid task number.\n";
    }
}

int main() {

    loadTasks();

    int choice;

    do {

        cout << "\n====== TO-DO LIST MENU ======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            addTask();
            break;

        case 2:
            viewTasks();
            break;

        case 3:
            markCompleted();
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while(choice != 4);

    return 0;
}