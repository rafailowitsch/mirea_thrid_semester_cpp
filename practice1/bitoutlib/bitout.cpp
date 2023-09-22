#include "bitout.h"

/*	function outputs binary and decimal
	representation of a number
*/
vector<string> outputBinaryAndDecimal(unsigned int decimalNumber, unsigned int numberOfDigits) {
	vector<string>	resultArray;

    resultArray.push_back(decimalToBinary(decimalNumber, numberOfDigits));
    resultArray.push_back(to_string(decimalNumber));

    return resultArray;
}

/*	conversion from decimal
	to binary number system
	in string format
*/
static string decimalToBinary(unsigned int decimalNumber, unsigned int numberOfDigits) {
	int 	        binaryNumber	    =	decimalNumber;
	string 		string_binaryNumber;

	for (size_t i = 0; i < numberOfDigits; i++)
	{
		if (binaryNumber % 2 == 1) string_binaryNumber = "1" + string_binaryNumber;
		else string_binaryNumber = "0" + string_binaryNumber;

		binaryNumber = binaryNumber / 2;
	}

	return string_binaryNumber;
}
