CC = gcc
CFLAGS = -g 
COMPILE = $(CC) $(CFLAGS)

all: calc format

calc: convertToDecimal.o convertToBase.o calc.o
	$(COMPILE) -o calc calc.o convertToDecimal.o convertToBase.o

calc.o: convertToDecimal.h convertToBase.h
	$(COMPILE) -c calc.c

convertToBase.o: convertToBase.c
	$(COMPILE) -c convertToBase.c

convertToDecimal.o: convertToDecimal.c
	$(COMPILE) -c convertToDecimal.c

format: inputs outputs format.o 
	$(COMPILE) -o format format.c binaryToDec.c floatToASCII.c intToDecASCII.c

format.o: binaryToDec.h intToDecASCII.h floatToASCII.h format.c
	$(COMPILE) -c format.c

inputs: binaryToDec.h binaryToDec.c
	$(COMPILE) -c binaryToDec.c

outputs: intToDecASCII.h intToDecASCII.c floatToASCII.h floatToASCII.c
	$(COMPILE) -c intToDecASCII.c floatToASCII.c

clean:
	rm *.o calc format
