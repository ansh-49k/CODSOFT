#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    // Seed the random number generator with the current time
    srand(time(nullptr));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    int userGuess;
    int numberOfGuesses = 0;

    cout << "Welcome to the Guess the Random Number Game!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        numberOfGuesses++;

        if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number (" << randomNumber << ") in " << numberOfGuesses << " guesses." << endl;
        }
    } while (userGuess != randomNumber);

    return 0;
}
