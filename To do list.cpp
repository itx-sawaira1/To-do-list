#include <iostream>
#include <string>

using namespace std;
struct node {
    string taskDescription;
    string status;
    node* link;
};

class ToDoList {
private:
    node *start, *cur, *temp;

public:
    ToDoList() {
        start = NULL;
    }
    void addTask() {
        temp = new node;
        cout << "Enter task ";
        cin >> temp->taskDescription;
        temp->status = "Pending";
        temp->link = NULL;

        if (start == NULL) {
            start = temp;
        } else {
            cur = start;
            while (cur->link != NULL) {
                cur = cur->link;
            }
            cur->link = temp;
        }
        cout << "Task added!" << endl;
}
    void displayTasks() {
        if (start == NULL) {
            cout << "The list is empty!" << endl;
            return;
        }
        cur = start;
        int count = 1;
        while (cur != NULL) {
            cout << count << ". " << cur->taskDescription << " [" << cur->status << "]" << endl;
            cur = cur->link;
            count++;
        }
    }
    void markAsCompleted() {
        int pos;
        cout << "Enter task number to mark as completed: ";
        cin >> pos;

        cur = start;
        for (int i = 1; i < pos && cur != NULL; i++) {
            cur = cur->link;
        }

        if (cur != NULL) {
            cur->status = "Completed";
            cout << "Task status updated!" << endl;
        } else {
            cout << "Invalid position!" << endl;
        }
    }
    void deleteTask() {
        int pos;
        cout << "Enter task number to delete: ";
        cin >> pos;

        if (start == NULL) return;

        if (pos == 1) {
            temp = start;
            start = start->link;
            delete temp;
            cout << "Task deleted." << endl;
        } else {
            cur = start;
            for (int i = 1; i < pos - 1 && cur != NULL; i++) {
                cur = cur->link;
            }
            if (cur != NULL && cur->link != NULL) {
                temp = cur->link;
                cur->link = temp->link;
                delete temp;
                cout << "Task deleted." << endl;
            } else {
                cout << "Invalid position!" << endl;
            }
        }
    }
    void updateTask() {
        int pos;
        cout << "Enter task number to update: ";
        cin >> pos;

        cur = start;
        for (int i = 1; i < pos && cur != NULL; i++) {
            cur = cur->link;
        }

        if (cur != NULL) {
            cout << "Enter new description: ";
            cin >> cur->taskDescription;
            cout << "Task updated!" << endl;
        }
    }
    void searchTask() {
        string find;
        cout << "Enter task name to search: ";
        cin >> find;
        cur = start;
        bool found = false;
        while (cur != NULL) {
            if (cur->taskDescription == find) {
                cout << "Task Found! Status: " << cur->status << endl;
                found = true;
                break;
            }
            cur = cur->link;
        }
        if (!found) cout << "Task not found." << endl;
    }
};

int main() {
    ToDoList myList;
    int choice;

    while (true) {
        cout << "To-Do List Menu " << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Mark Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Update Task" << endl;
        cout << "6. Search Task" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) myList.addTask();
        else if (choice == 2) myList.displayTasks();
        else if (choice == 3) myList.markAsCompleted();
        else if (choice == 4) myList.deleteTask();
        else if (choice == 5) myList.updateTask();
        else if (choice == 6) myList.searchTask();
        else if (choice == 7) break;
        else cout << "Invalid choice! Try again." << endl;
    }

    return 0;
}
