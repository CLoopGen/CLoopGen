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
    int len_a = a->length;
    int offset = (length - 1) / 2 - (len_a - 1) / 2;
    double *vec_coeff = vec->coeff;
    double *a_coeff = a->coeff;
    for (i = 0; i < len_a; i++) {
        vec_coeff[i + offset] += a_coeff[i];
    }
}
