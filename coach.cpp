
#include <iostream>
using namespace std;

struct Coach {
    int coachNo;
    Coach* next;
};

Coach* head = nullptr;

void addBeginning(int n) {
    Coach* newCoach = new Coach{n, head};
    head = newCoach;
    cout << "Coach added at the beginning.\n";
}

void addEnd(int n) {
    Coach* newCoach = new Coach{n, nullptr};

    if (head == nullptr) {
        head = newCoach;
    } else {
        Coach* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newCoach;
    }

    cout << "Coach added at the end.\n";
}

void removeCoach(int n) {
    Coach* temp = head;
    Coach* prev = nullptr;

    while (temp != nullptr && temp->coachNo != n) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Coach not found.\n";
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Coach removed successfully.\n";
}

void display() {
    Coach* temp = head;

    if (temp == nullptr) {
        cout << "No coaches in the train.\n";
        return;
    }

    cout << "Train: ";
    while (temp != nullptr) {
        cout << "Coach" << temp->coachNo << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, n;

    do {
        cout << "\n--- Train Coach Management ---\n";
        cout << "1. Add Coach at Beginning\n";
        cout << "2. Add Coach at End\n";
        cout << "3. Remove Coach\n";
        cout << "4. Display Coaches\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter coach number: ";
                cin >> n;
                addBeginning(n);
                break;

            case 2:
                cout << "Enter coach number: ";
                cin >> n;
                addEnd(n);
                break;

            case 3:
                cout << "Enter coach number to remove: ";
                cin >> n;
                removeCoach(n);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    // Free remaining coaches
    while (head != nullptr) {
        Coach* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
