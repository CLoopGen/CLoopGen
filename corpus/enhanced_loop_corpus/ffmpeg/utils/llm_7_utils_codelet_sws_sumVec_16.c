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
    int mid_a = (len_a - 1) / 2;
    int mid_len = (length - 1) / 2;
    double *vec_coeff = vec->coeff;
    double *a_coeff = a->coeff;
    for (i = 0; i < len_a; i++) {
        int j = len_a - 1 - i; // Reverse index to introduce different access pattern
        vec_coeff[j + mid_len - mid_a] += a_coeff[j];
    }
}
