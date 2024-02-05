#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(int num) {
    stack<int> digitStack;
    int originalNum = num;

    // Pushing each digit ont he Stack
    while (num > 0) {
        int digit = num % 10;
        digitStack.push(digit);
        num /= 10;
    }

    // Pop each digit from the stack and compare with the original number
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
