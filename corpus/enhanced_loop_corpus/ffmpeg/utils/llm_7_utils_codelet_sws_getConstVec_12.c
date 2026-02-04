#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern double c;
extern int length;
extern int i;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *coeff = vec->coeff;
    double temp = c;
    for (i = 0; i < length; i++) {
        temp = temp + c - c; // WAW on `temp`, eliminating loop-carried dependence on prior writes to `temp`
        coeff[i] = temp;
    }
}
