#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern SwsVector *b;
extern int i;
extern int j;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < a->length; i++) {
        vec->coeff[i] += a->coeff[i] * b->coeff[0];
    }
    for (j = 1; j < b->length; j++) {
        vec->coeff[j] += a->coeff[0] * b->coeff[j];
    }
}
