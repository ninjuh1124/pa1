#include <stdio.h>

// converts a string of binary characters to a two's compiment integer
int binaryToDec(char * input, int * output) {
    int pos;
    int value = 0;
    for (pos=0; input[pos]!='\0'; pos++) {
        if (input[pos] == '0' || input[pos] == '1') {
            value = value*2 + (input[pos]-'0');
        } else { return 0; }
    }
    *output = value;
    if (pos == 32) { return 1; }
    else { return 0; }
}
