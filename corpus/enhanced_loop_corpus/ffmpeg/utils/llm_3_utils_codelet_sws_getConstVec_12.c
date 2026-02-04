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
    // Variant 2: Reverse consecutive memory access
    for (i = length - 1; i >= 0; i--)
        vec->coeff[i] = c;
}
