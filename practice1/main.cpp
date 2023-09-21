#include <iostream>
#include <stdint.h>

#include "bitlib/bit_operations.h"
#include "bitoutlib/bitout.h"

using namespace std;

int main() {
    unsigned int    binaryСonstant;      // binary representation of a constant
    unsigned int    number;              // user entered number
    unsigned int    bitNumber;           // number of the bit to be replaced in the binary number
    bool            flag;                // flag responsible for program cycling
    size_t          alternativeNumber;   // number of the function selected by the user
    vector <string> result;              // vector containing bitout function results

    binaryСonstant = 0b111010;                // binary representation of a number 58
    flag = true;

    while (flag) {
        puts("\n"
             " ┌─────────bitwise─operations─────────┐\n"
             " ├ 1. three bits to one from right    │\n"
             " ├ 2. thee bits to one from left      │\n"
             " ├ 3. offset by six bits to the left  │\n"
             " ├ 4. offset by six bits to the right │\n"
             " ├ 5. n-th bit in one                 │\n"
             " ├ 6. exit                            │\n"
             " └────────────────────────────────────┘\n");

        cout << " select a function and enter its number" << endl << " -> ";
        cin >> alternativeNumber;
        puts("");

        switch(alternativeNumber) {
            case 1:
                changeLastThreeBitsToOnesFromRight(&binaryСonstant);
                
                result = outputBinaryAndDecimal(binaryСonstant, 16);
                cout << " ┌ bin: " << result[0] << endl << " └ dec: " << result[1] << endl;
                break;

            case 2:
                changeLastThreeBitsToOnesFromLeft(&binaryСonstant);

                result = outputBinaryAndDecimal(binaryСonstant, 16);
                cout << " ┌ bin: " << result[0] << endl << " └ dec: " << result[1] << endl;
                break;

            case 3:
                cout << " enter the number" << endl << " -> ";
                cin >> number;
                puts("");

                multiplyUsingBitwise(&number);

                result = outputBinaryAndDecimal(number, 16);
                cout << " ┌ bin: " << result[0] << endl << " └ dec: " << result[1] << endl;
                break;

            case 4:
                cout << " enter the number and bit" << endl << " -> ";
                cin >> number;
                puts("");

                divideUsingBitwise(&number);

                result = outputBinaryAndDecimal(number, 16);
                cout << " ┌ bin: " << result[0] << endl << " └ dec: " << result[1] << endl;
                break;

            case 5:
                cout << " enter the number and bit number" << endl << " -> ";
                cin >> number >> bitNumber;
                puts("");
                
                changeNthBitToOne(&number, bitNumber);

                result = outputBinaryAndDecimal(number, 16);
                cout << " ┌ bin: " << result[0] << endl << " └ dec: " << result[1] << endl;
                break;

            default:
                flag = false;
                break;
        }
    }

    return 0;
}