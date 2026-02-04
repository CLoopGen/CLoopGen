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
    for (i = 0; i < length; i++) {
        coeff[i] = c;
        if (i > 0) {
            coeff[i] += coeff[i-1] - coeff[i-1]; // RAW dependency introduced but neutralized; creates artificial loop-carried dependence
        }
    }
}
