#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern int shift;
extern int length;
extern int i;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *a_coeff = a->coeff;
    double *vec_coeff = vec->coeff;
    int a_len = a->length;
    int offset = (length - 1) / 2 - (a_len - 1) / 2 - shift;
    for (i = 0; i < a_len; i++) {
        vec_coeff[i + offset] = a_coeff[i];
    }
}
