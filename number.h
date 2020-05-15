#ifndef NUMBER_H
#define NUMBER_H

// maps an two's compliment bit pattern to a floating point number
union Number {
    int i;
    float f;
};

#endif
