// Michael McCain
// 11/29/2022
// Leet Code - 13
// Roman to Int
// This program converts roman numerals to integer values

// libraries
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#include<iostream>
#include <string>
#include<map>
#include<iterator>
#include<cstring>
using namespace std;

// Prototypes
int romanToInt(string);
int main() {    
    //Initializers
    const int SZ = 10;
    char numeral [SZ];
    bool vrfy = false;
    int fValue = 0;

    // Gather input
    cout << "\nPlease, input a roman numeral between 1 and 3999>" << endl;
    cin.get(numeral,SZ);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Process input
    fValue = romanToInt(numeral);
    cout << "\nThe converted value is " << fValue << "." << endl;
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