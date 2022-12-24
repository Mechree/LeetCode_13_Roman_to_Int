// Michael McCain
// 11/29/2022
// Leet Code - 13
// Roman to Int
// This program converts roman numerals to integer values

// libraries
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include<map>
#include<iterator>
#include<cstring>
using namespace std;

// Prototypes
int romanToInt(string);
int main() {
    //Initializers
    const int SZ = 10;
    char numeral[SZ];
    bool vrfy = false;
    int fValue = 0;
    string repeat = "";

    do 
    {
        // Gather input
        cout << "\nPlease, input a roman numeral between 1 and 3999>" << endl;
        cin.get(numeral, SZ);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //Process input
        fValue = romanToInt(numeral);
        
        // Verify value is less than 4000 or greater than 1
        if (fValue >= 4000 || fValue < 1)
        {
            cout << "\nYou entered an invalid roman numeral value. Please try again." << endl;
            vrfy = false;
        }
        else 
        {
            cout << "\nThe converted value is " << fValue << "." << endl; 

            // Ask user if they would like to continue
            cout << "\nWould you like to convert another roman numeral, Y or N?>" << endl;
            cin >> repeat;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (repeat == "N"|| repeat == "n") {
                vrfy = true;
            }
        }
    } while (vrfy == false);


}
// Functions

    // Convert to integer
int romanToInt(string input) {
    // initalize variables
    int temp = 0;
    int strSz = input.size() - 1;
    int ans = 0;
    map <char, int> RomanValuesMap = {
        {'I', 1},
        {'V', 5 },
        {'X', 10},
        {'L', 50 },
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

        // Iterate through values from right to left; adding or subtracting depending on conditions
    for (int i = strSz; i >= 0; i--)
    {
        if (RomanValuesMap[input[i]] >= temp) {
            ans = ans + RomanValuesMap[input[i]];
        }
        else {
            ans = ans - RomanValuesMap[input[i]];
        }
        temp = RomanValuesMap[input[i]];
    }
    return ans;
}