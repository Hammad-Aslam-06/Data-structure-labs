#include <iostream>
#include <string>
using namespace std;

class myCarStack {
private:
    string arr[8];
    int top;

public:
    myCarStack() {
        top = -1;
    }

    bool isFull() {
        return top == 7;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(string car) {
        if (isFull()) {
            cout << "Parking is full!" << endl;
            return;
        }
        arr[++top] = car;
        cout << "Car parked: " << car << endl;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }
        return arr[top--];
    }

    string peek() {
        if (isEmpty()) return "";
        return arr[top];
    }

    int count() {
        return top + 1;
    }

    // Display cars
    void display() {
        if (isEmpty()) {
            cout << "No cars parked." << endl;
            return;
        }
        cout << "Cars in parking (top to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    // Search car
    bool search(string car) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == car)
                return true;
        }
        return false;
    }

    // Remove specific car
    void removeCar(string car) {
        if (isEmpty()) {
            cout << "Parking is empty!" << endl;
            return;
        }

        myCarStack temp;
        bool found = false;

        // Remove cars until target is found
        while (!isEmpty()) {
            string current = pop();

            if (current == car) {
                cout << "Car removed: " << car << endl;
                found = true;
                break;
            } else {
                temp.push(current);
            }
        }

        if (!found) {
            cout << "Car not found!" << endl;
        }

        // Put back remaining cars
        while (!temp.isEmpty()) {
            push(temp.pop());
        }
    }
};

int main() {
    myCarStack parking;
    int choice;
    string carNo;

    do {
        cout << endl;
        cout << "--- Parking Lot Menu ---" << endl;
        cout << "1. Park Car" << endl;
        cout << "2. Remove Car" << endl;
        cout << "3. View Parked Cars" << endl;
        cout << "4. Total Cars" << endl;
        cout << "5. Search Car" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> carNo;
            parking.push(carNo);
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> carNo;
            parking.removeCar(carNo);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "Total cars parked: " << parking.count() << endl;
            break;

        case 5:
            cout << "Enter car number to search: ";
            cin >> carNo;
            if (parking.search(carNo))
                cout << "Car found!" << endl;
            else
                cout << "Car not found!" << endl;
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}