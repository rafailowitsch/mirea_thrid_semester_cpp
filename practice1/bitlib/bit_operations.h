#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

#include <iostream>

using namespace std;

#define REPLACE_LEFTMOST_THREE_BITS         0b111000             // constant for replacing the leftmost three bits
#define REPLACE_RIGHTMOST_THREE_BITS        0b1110000000000000   // constant for replacing the rightmost three bits
#define SHIFT_BY_SIX                        6                    // shift by six positions
#define ONE_BIT_IN_LEAST_SIGNIFICANT_DIGIT  0b1                  // one bit in the least significant digit (leftmost)

void changeLastThreeBitsToOnesFromRight(unsigned int *number); 
void changeLastThreeBitsToOnesFromLeft(unsigned int *number);  
void multiplyUsingBitwise(unsigned int *number); 
void divideUsingBitwise(unsigned int *number); 
void changeNthBitToOne(unsigned int *number, int n); 

#endif //BIT_OPERATIONS_H