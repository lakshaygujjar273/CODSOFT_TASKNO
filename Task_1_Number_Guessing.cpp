#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int num = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "===================================" << endl;
    cout << " Welcome to the Number Guessing Game!" << endl;
    cout << " I'm thinking of a number between 1 and 100." << endl;
    cout << "===================================" << endl;

    while (true) {
        cout << "\nEnter your guess: ";
        cin >> guess;

        attempts = attempts + 1;

        if (guess > num) {
            cout << "Too high! Try a smaller number." << endl;
        }
        else if (guess < num) {
            cout << "Too low! Try a bigger number." << endl;
        }
        else {
            cout << "\nCongratulations! You guessed it right!" << endl;
            cout << "The number was: " << num << endl;
            cout << "It took you " << attempts << " attempts." << endl;
            break;
        }
    }

    return 0;
}