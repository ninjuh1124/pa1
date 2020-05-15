#include <stdio.h>

/**
 * function takes in a memeory address of a char array
 * the array is paresed through looking for invalid chars
 * 
 * char input       address of first char in array
 */
int validFormat(char * input) {
    int pos = 0;
    switch (input[pos]) {
        case 'b':
            for (pos++; input[pos]!='\0'; pos++) {
                if (!(input[pos] == '0' || input[pos] == '1')) { return 0; }
            }
            if (pos > 65) { return 0; }
            break;
        case 'o':
            for (pos++; input[pos]!='\0'; pos++) {
                if (!(input[pos] >= '0' && input[pos] <= '7')) { return 0; }
            }
            if (pos > 23) { return 0; }
            break;
        case 'x':
            for (pos++; input[pos]!='\0'; pos++) {
                if (!((input[pos] >= '0' && input[pos] <= '9') || (input[pos] >= 'a' && input[pos] <= 'f'))) { return 0; }
            }
            if (pos > 17) { return 0; }
            break;
        case 'd':
            for (pos++; input[pos]!='\0'; pos++) {
                if (!(input[pos] >= '0' && input[pos] <= '9')) { return 0; }
            }
            break;
        case '-':
            if (input[1] != 'd') { return 0; }
            for (pos=2; input[pos]!='\0'; pos++) {
                if (!(input[pos] >= '0' && input[pos] <= '9')) { return 0; }
            }
            break;
        default : return 0;
    }
    // if none of these traps trigger
    return 1;
}

/**
 * function takes a memory address of a char array
 * the array is parsed character by character to produce a two's complement number
 * the two's complement number is stored in the given output address
 *
 * char input           address of first char in array
 * long long output     address of 64-bit two's complement integer 
 */
void convertToDecimal(char * input, long long * output) {
    if (validFormat(input)) {
        int pos = 0;
        long long value = 0;
        switch (input[pos]) {
            case 'b':
                for (pos++; input[pos]!='\0'; pos++) {
                    value = 2*value + input[pos] - '0';
                }
                break;
            case 'o':
                for (pos++; input[pos]!='\0'; pos++) {
                    value = 8*value + input[pos] - '0';
                }
                break;
            case 'd':
                for (pos++; input[pos]!='\0'; pos++) {
                    value = 10*value + input[pos] - '0';
                }
                break;
            case 'x':
                for (pos++; input[pos]!='\0'; pos++) {
                    if (input[pos] > '9') { input[pos] -= '\''; }
                    value = 16*value + input[pos] - '0';
                }
                break;
            case '-':
                for (pos=2; input[pos]!='\0'; pos++) {
                    value = 10*value + input[pos] - '0';
                }
                value *= -1;
                break;
        }
        *output = value;
    } else { fprintf(stderr, "Number format error\n"); }
}
