#include <stdio.h>
#include <string.h>

// converts an integer to a decimal ascii string
void intToDecASCII(int x, char * output) {
    char reverseString[30];
    int value, i=0, size, isNegative = 0, pos = 0;
    
    if (x < 0) {
        isNegative = 1;
        x *= -1;
    }
    reverseString[pos++] = '\0';
    while (x != 0) {
        value = x % 10;
        reverseString[pos++] = value + '0';
        x = x / 10;
    }
    if (isNegative) { reverseString[pos++] = '-'; }
    size = pos;
    while (pos > 0) {
        output[i++] = reverseString[--pos];
    }
}

