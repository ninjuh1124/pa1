#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "floatToASCII.h"
#include "intToDecASCII.h"
#include "binaryToDec.h"
#include "number.h"

int main(int argc, char**argv) {
    // argv[0] = ./format
    // argv[1] = binary input string
    // argv[2] = output format
    
    int tCompliment, validArgs = 1;
    float numf;
    union Number num;
    char * result = malloc(sizeof(char) * 20);
    // validate input string    
    if (binaryToDec(&argv[1][0], &tCompliment)) { 
        num.i = tCompliment;
        if (strcmp(&argv[2][0], "float") == 0) {
            numf = num.f;
printf("Passing %e to function\n", numf);
            floatToASCII(numf, result);
        } else if (strcmp(&argv[2][0], "int") == 0) {
            intToDecASCII(num.i, result);
        } else {
            fprintf(stderr, "Output format error\n");
        }
        printf("%s\n", result);
    }
    else { fprintf(stderr, "Number format error\n"); }
    free(result);
    return 0;
}
