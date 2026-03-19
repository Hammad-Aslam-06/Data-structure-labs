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
    T* minArr;     
    int capacity;
    int topIndex;
    int minTop;

public:
    
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        minArr = new T[capacity];
        topIndex = -1;
        minTop = -1;
    }

    
    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }

    
    void push(T value) override {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        arr[++topIndex] = value;

      
        if (minTop == -1 || value <= minArr[minTop]) {
            minArr[++minTop] = value;
        }

        cout << value << " pushed into stack." << endl;
    }

   
    T pop() override {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return T();
        }

        T popped = arr[topIndex--];

       
        if (popped == minArr[minTop]) {
            minTop--;
        }

        return popped;
    }

    
    T top() const override {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
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
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements (top to bottom):" << endl;
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    
    T getMin() const {
        if (minTop == -1) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return minArr[minTop];
    }
};


int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    myStack<int> s(size);

    int choice, value;

    do {
        cout << endl;
        cout << "--- Enhanced Stack Menu ---" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Show top element" << endl;
        cout << "4. Check if stack is empty" << endl;
        cout << "5. Check if stack is full" << endl;
        cout << "6. Display stack elements" << endl;
        cout << "7. Show minimum element" << endl;
        cout << "8. Exit" << endl;
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
            cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
            break;

        case 5:
            cout << (s.isFull() ? "Stack is full" : "Stack is not full") << endl;
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Minimum element: " << s.getMin() << endl;
            break;

        case 8:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}