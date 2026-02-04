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
    int len_b = b->length;
    int offset = (length - 1) / 2 - (len_b - 1) / 2;
    double *vec_coeff = vec->coeff;
    double *b_coeff = b->coeff;
    double temp_sum = 0.0;
    for (i = 0; i < len_b; i++) {
        temp_sum += b_coeff[i];
    }
    for (i = 0; i < len_b; i++) {
        vec_coeff[i + offset] += temp_sum / len_b;
    }
}
