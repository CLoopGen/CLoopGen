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
    double factor = c * c + 1.0;
    for (i = 0; i < length; i++) {
        vec->coeff[i] = factor * (double)(i % 4);
    }
}
