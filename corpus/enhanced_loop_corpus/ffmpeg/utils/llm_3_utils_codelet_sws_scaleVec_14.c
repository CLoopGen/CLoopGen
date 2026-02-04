#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern double scalar;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int len = a->length;
    double *coeff = a->coeff;
    for (i = len - 1; i >= 0; i--)
        coeff[i] *= scalar;
}
