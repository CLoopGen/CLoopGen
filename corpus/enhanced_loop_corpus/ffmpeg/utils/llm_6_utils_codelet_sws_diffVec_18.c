#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern int length;
extern int i;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (length - 1) / 2 - (a->length - 1) / 2;
    double *vec_coeff = vec->coeff;
    double *a_coeff = a->coeff;
    int len = a->length;
    for (i = 0; i < len; i++) {
        vec_coeff[i + start] += a_coeff[i];
    }
}
