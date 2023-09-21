#ifndef BITOUT_H
#define BITOUT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> outputBinaryAndDecimal(unsigned int decimalNumber, unsigned int numberOfDigits);
static string decimalToBinary(unsigned int decimalNumber, unsigned int numberOfDigits);

#endif //BITOUT_H