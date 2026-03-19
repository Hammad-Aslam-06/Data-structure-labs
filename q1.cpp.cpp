#include <iostream>
using namespace std;


template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};


template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

   
    ~myStack() {
        delete[] arr;
    }

    
    void push(T value) override {
        if (isFull()) {
            cout << "Stack Overflow!"<<endl;
            return;
        }
        arr[++topIndex] = value;
        cout << value << " pushed into stack."<<endl;
    }

   
    T pop() override {
        if (isEmpty()) {
            cout << "Stack Underflow!"<<endl;
            return T(); 
        }
        return arr[topIndex--];
    }

   
    T top() const override {
        if (isEmpty()) {
            cout << "Stack is empty!"<<endl;
            return T();
        }
        return arr[topIndex];
    }

 
    bool isEmpty() const override {
        return topIndex == -1;
    }

    
    bool isFull() const override {
        return topIndex == capacity - 1;
    }

    
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!"<<endl;
            return;
        }
        cout << "Stack elements (top to bottom):"<<endl;
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};


int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    myStack<int> s(size);

    int choice, value;

    do {
        cout << "--- Stack Menu ---"<<endl;
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Popped: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top element: " << s.top() << endl;
            break;

        case 4:
            cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty")<<endl;
            break;

        case 5:
            cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n")<<endl;
            break;

        case 6:
            s.display();
            break;

        case 0:
            cout << "Exiting..."<<endl;
            break;

        default:
            cout << "Invalid choice!"<<endl;
        }

    } while (choice != 0);

    return 0;
}