#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "convertToDecimal.h"
#include "convertToBase.h"

int main(int argc, char**argv) {
    int validArgs = 1;
    long long * num1 = malloc(sizeof(long long));
    long long * num2 = malloc(sizeof(long long));
    long long num3;
    char result[65];
    // argv[0] = ./test
    // argv[1] = operation
    // argv[2] = num1
    // argv[3] = num2
    // argv[4] = output base
   
    // validate operation
    if (!(argv[1][0] == '+' || argv[1][0] == '-')) {
        validArgs = 0;
        fprintf(stderr, "Invalid operation\n");
    }

    // validate numbers
    if (!(validFormat(argv[2]) && validFormat(argv[3]))) {
        validArgs = 0;
        fprintf(stderr, "Number format error\n");
    } else {
        convertToDecimal(&argv[2][0], num1);
        convertToDecimal(&argv[3][0], num2);
    }

    // validate output base
    if (!(argv[4][0] != 'd' || argv[4][0] != 'o' || argv[4][0] != 'b' || argv[4][0] != 'x')) {
        validArgs = 0;
        fprintf(stderr, "Invalid output base\n");
    }

    if (validArgs) { 
        if (argv[1][0] == '+') { num3 = *num1 + *num2; }
        else { num3 = *num1 - *num2; }
        
        convertToBase(&num3, argv[4], result);
    }

    printf("%s\n", result);
    free(num1);
    free(num2);
    return 0;
}
