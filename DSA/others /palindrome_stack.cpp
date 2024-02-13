#include <iostream>

using namespace std;


class Stack {
private:
    static const int MAX_SIZE = 10; 
    int arr[MAX_SIZE];
    int topIndex; 

public:
    Stack() {
        topIndex = -1; 
    }


    void push(int value) {
        if (topIndex < MAX_SIZE - 1) {
            topIndex++;
            arr[topIndex] = value;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    int pop() {
        if (!empty()) {
            int topValue = arr[topIndex];
            topIndex--;
            return topValue;
        } else {
            cout << "Stack underflow!" << endl;
            return -1; 
        }
    }

 
    int top() {
        if (!empty()) {
            return arr[topIndex];
        } else {
            cout << "Stack is empty!" << endl;
            return -1; 
        }
    }

 
    bool empty() {
        return topIndex == -1;
    }
};


bool isPalindrome(int num) {
    Stack digitStack;
    int originalNum = num;

  // push each digit into the stack.
    while (num > 0) {
        int digit = num % 10;
        digitStack.push(digit);
        num /= 10;
    }

    // Pop each digit from the stack and compare iy with the original number
    while (!digitStack.empty()) {
        int digit = digitStack.top();
        digitStack.pop();

        if (digit != originalNum % 10) {
            return false; 
        }

        originalNum /= 10;
    }

    return true; 
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}
