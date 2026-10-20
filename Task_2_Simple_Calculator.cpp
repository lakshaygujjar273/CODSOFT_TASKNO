#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;

    cout << "===================================" << endl;
    cout << "        Simple Calculator" << endl;
    cout << "===================================" << endl;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    switch (op) {
        case '+':
            result = num1 + num2;
            cout << "\nResult: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "\nResult: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "\nResult: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "\nError: Division by zero is not allowed." << endl;
            } else {
                result = num1 / num2;
                cout << "\nResult: " << num1 << " / " << num2 << " = " << result << endl;
            }
            break;
        default:
            cout << "\nInvalid operator. Please use +, -, * or /." << endl;
    }

    return 0;
}