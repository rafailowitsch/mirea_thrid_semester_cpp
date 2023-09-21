#include "bit_operations.h"


/* changes the last three bits to ones
  starting from the third bit from the right
  in the binary representation of the number
  (considering the zeroth bit)
*/
void changeLastThreeBitsToOnesFromRight(unsigned int *number) {
    int mask = REPLACE_LEFTMOST_THREE_BITS;
    (*number) |= mask;
}

/*  changes the last three bits to ones
    starting from the third bit from the left
    in the binary representation of the number
    (considering the zeroth bit)
*/
void changeLastThreeBitsToOnesFromLeft(unsigned int *number) {
    int mask = REPLACE_RIGHTMOST_THREE_BITS;
    (*number) |= mask;
}

/*  multiplies the value of an integer variable
    entered by the user by a multiplier
    using the appropriate bitwise operation
*/
void multiplyUsingBitwise(unsigned int *number) {
    (*number) <<= SHIFT_BY_SIX;
}

/*  divides the value of an integer variable
    entered by the user by a divisor
    using the appropriate bitwise operation
*/
void divideUsingBitwise(unsigned int *number) {
    (*number) >>= SHIFT_BY_SIX;
}

/*  changes the nth bit to one
    in the binary representation
    of the number entered by the user  
*/
void changeNthBitToOne(unsigned int *number, int n) {
    int mask = ONE_BIT_IN_LEAST_SIGNIFICANT_DIGIT;
	mask <<= n;
	(*number) |= mask;
}


