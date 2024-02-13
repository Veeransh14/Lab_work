#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool isPalindrome(int num) {
    queue<int> q;
    stack<int> s;

    // Enqueue each digit of the number into the queue and stack
    int temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        q.push(digit);
        s.push(digit);
        temp /= 10;
    }

    // Dequeue from the queue and pop from the stack to compare digits
    while (!q.empty()) {
        int digitFromQueue = q.front();
        q.pop();

        int digitFromStack = s.top();
        s.pop();

        if (digitFromQueue != digitFromStack) {
            return false; // Not a palindrome
        }
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
