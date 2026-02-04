#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *b;
extern int length;
extern int i;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *vec_coeff = vec->coeff;
    double *b_coeff = b->coeff;
    int offset = (length - 1) / 2 - (b->length - 1) / 2;
    int len = b->length;
    for (i = 0; i < len; i++) {
        vec_coeff[i + offset] -= b_coeff[i];
    }
}
