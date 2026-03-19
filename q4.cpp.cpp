#include <iostream>
#include <stack>
using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:
   
    void type(char ch) {
        undoStack.push(text);
        text += ch;

    
        while (!redoStack.empty()) redoStack.pop();

        cout << "Text: " << text << endl;
    }

    
    void del() {
        if (text.empty()) {
            cout << "Nothing to delete!" << endl;
            return;
        }

        undoStack.push(text);
        text.pop_back();

        while (!redoStack.empty()) redoStack.pop();

        cout << "Text: " << text << endl;
    }

   
    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo!" << endl;
            return;
        }

        redoStack.push(text);
        text = undoStack.top();
        undoStack.pop();

        cout << "Undo -> Text: " << text << endl;
    }

   
    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo!" << endl;
            return;
        }

        undoStack.push(text);
        text = redoStack.top();
        redoStack.pop();

        cout << "Redo -> Text: " << text << endl;
    }

   
    void display() {
        cout << "Current Text: " << text << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;
    char ch;

    do {
        cout << endl;
        cout << "--- Text Editor Menu ---" << endl;
        cout << "1. Type Character" << endl;
        cout << "2. Delete Character" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Display Text" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter character: ";
            cin >> ch;
            editor.type(ch);
            break;

        case 2:
            editor.del();
            break;

        case 3:
            editor.undo();
            break;

        case 4:
            editor.redo();
            break;

        case 5:
            editor.display();
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