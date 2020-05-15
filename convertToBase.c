#include <stdio.h>

/**
 * function takes in a memroy address of a 64-bit two's complement integer
 * a formatted string is generated and output to a specified address
 *
 * long long input      address of integer
 * char base            address of output base (b|o|d|x)
 * char output          address for output string
 */
void convertToBase(long long * input, char * base, char * output) {
    int pos = 0;        // position in the reversString
    int i = 0;          // position in the output string
    int carry = 0;
    int isNegative, div, value;
    char reverseString[65];

    if (*input < 0) {
        isNegative = 1;
        *input *= -1;
    } else { isNegative = 0; }
    
    // set divisor based on base system
    switch (*base) {
        case 'b': div = 2;
                  break;
        case 'o': div = 8;
                  break;
        case 'd': div = 10;
                  break;
        case 'x': div = 16;
                  break;
        default : fprintf(stderr, "Invalid output base\n");
                  return;
    }
    
    // generate the reverse string from two's complement number
    reverseString[pos++] = '\0';
    if (*input == 0) { reverseString[pos++] = '0'; }
    else {
        while (*input != 0) {
            value = *input % div;
            if (value >= 10) { value += 39; }
            reverseString[pos++] = value + '0';
            *input = *input / div;
        }
    }

    // flip bits if necessary and add base tag
    if (isNegative) {
        if (*base == 'd') {
            reverseString[pos++] = '-';
        } else {
            for (pos=pos; pos<=64; pos++) { reverseString[pos] = '0'; }
            // flip bits
            // probably should have made this it's own function but w/e
            pos = 0;
            carry = 1;
            switch (*base) {
                case 'b':
                    for (pos++; pos<=64; pos++) {
                       reverseString[pos] = '1' - (reverseString[pos] - '0');
                    }
                    // add 1
                    pos = 1;
                    do {
                        reverseString[pos] += carry;
                        carry = 0;
                        if (reverseString[pos] > '1') {
                            reverseString[pos] = '0';
                            carry++;
                            pos++;
                        }
                    } while (carry != 0);
                    pos = 65;
                    break;

                case 'o':
                    for (pos++; pos<=20; pos++) {
                       reverseString[pos] = '7' - (reverseString[pos] - '0');
                    }
                    reverseString[pos++] = '1';
                    // add 1
                    pos = 1;
                    do {
                        reverseString[pos] += carry;
                        carry = 0;
                        if (reverseString[pos] > '7') {
                            reverseString[pos] = '0';
                            carry++;
                            pos++;
                        }
                    } while (carry != 0);
                    pos = 22;
                    break;

                case 'x':
                    for (pos++; pos<=16; pos++) {
                        if (reverseString[pos] > '9') { reverseString[pos] -= 39; }
                        reverseString[pos] = '?' - (reverseString[pos] - '0');
                        if (reverseString[pos] > '9') { reverseString[pos] += 39; }
                    }
                    // add 1
                    pos = 1;
                    do {
                        reverseString[pos] += carry;
                        if (reverseString[pos] > '0' && reverseString[pos] < 'a') { reverseString[pos] += 39; }
                        carry = 0;
                        if (reverseString[pos] > 'f') {
                            reverseString[pos] = '0';
                            carry++;
                            pos++;
                        }
                    } while (carry != 0);
                    pos = 17;
                    break;
            }
            reverseString[pos++] = *base;
        }
    } else { reverseString[pos++] = *base; }
    
    // reverse the generated string into output address
    while (pos > 0) {
        output[i++] = reverseString[--pos];
    }
}
