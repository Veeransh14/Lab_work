#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(int num) {
    stack<int> digitStack;
    int originalNum = num;

    // Push each digit of the number onto the stack
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
            return false; // Not a palindrome
        }

        originalNum /= 10;
    }

    return true; // Palindrome
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
