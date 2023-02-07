/******************
Create a guessing game that a user is given a set amount of guesses to find either a specific number or word. They are given 5 numbers to try to guess the order.
Let the user know whether the number is not included, the number is included but in the wrong spot, or the number is included and in the right spot.
Wordle Clone essentially
******************/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Struct that holds the correct number the user should guess
struct vect {
    vector<char> randNum;
};

int main()
{
    vect v;
    string userInput;
    char tempAssign[5];
    const char nums[11] = "0123456789";
    char temp;
    int count = 0;
    int winCount = 0;
    int userCount = 0;
    int badCount = 0;

    // Loop to generate random char sequence and store in the vector
    // change this to do while
    srand(time(0));
    do {
        temp = nums[rand() % 10];
        for (int x = 0; x < v.randNum.size(); x++) {
            if (temp == v.randNum.at(x)) {
                count = count + 1;
            }
        }
        if (count == 0) {
            v.randNum.push_back(temp);
        }
        else { count = 0; }

    } while (v.randNum.size() != 5);

    // Displaying randomized number
    for (int u = 0; u < 5; u++) {
        cout << v.randNum.at(u);
    }
    cout << endl;

    // Beginning cout statements for rules
    cout << "Hello! Thanks for taking the time to play Numble!" << endl << endl << "Rules: " << endl;
    cout << "1. Enter a 5 digit number using Integers 0-9 ONLY, no repeating numbers." << endl;
    cout << "2. Guesses with an 'X' symbol are not included in the randomly generated number..." << endl;
    cout << "3. Guesses with an '@' symbol are included in the randomly generated number but not in the correct spot." << endl;
    cout << "4. Guesses with a '#' symbol are included in the randomly generated number and are in the correct spot!" << endl << endl;

    // User input to guess the number
    for (int q = 0; q < 5; q++) {
        do {
            cout << "Enter 5 integers using integers 0-9 (there are NO repeating numbers): ";
            cin >> userInput;
        } while (userInput.length() != 5);

        // convert userInput string to char array
        for (int j = 0; j < 5; j++) {
            tempAssign[j] = userInput[j];
        }
        cout << endl;

        // outputting userInput to screen for user reference
        for (int s = 0; s < 5; s++) {
            cout << tempAssign[s] << " ";
        }
        cout << endl;

        // testing if numbers match, outputting results
        for (int pos = 0; pos < 5; pos++) {
            char val = tempAssign[pos];
            int arr[5];

            copy(v.randNum.begin(), v.randNum.end(), arr);
            int found = distance(arr, find(arr, arr + 5, val));

            if (found == pos) {
                cout << "# ";
            }
            else if (found >= 0 && found < 5) {
                cout << "@ ";
            }
            else { cout << "X "; }
        }

        // determine if winning number
        for (int d = 0; d < 5; d++) {
            if (tempAssign[d] == v.randNum.at(d)) {
                winCount++;
            }
        }
        if (winCount == 5) {
            cout << endl << endl << "Congrats! That is the correct number! Thanks for playing!!" << endl;
            system("pause");
            return 0;
        }
        else {
            winCount = 0;
        }

        cout << endl << endl;
    }

    cout << "You did not guess the correct number. The correct number was: ";
    for (int u = 0; u < 5; u++) {
        cout << v.randNum.at(u);
    }
    cout << "... Thanks for playing, give it another shot!!" << endl << endl;

    system("pause");
    return 0;
}

