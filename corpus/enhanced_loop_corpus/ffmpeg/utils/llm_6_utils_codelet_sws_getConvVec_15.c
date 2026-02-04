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
    int len_a = a->length;
    int len_b = b->length;
    double *vec_coeff = vec->coeff;
    double *a_coeff = a->coeff;
    for (i = 0; i < len_a; i++) {
        double a_val = a_coeff[i];
        for (j = 0; j < len_b; j++) {
            vec_coeff[i + j] += a_val * b->coeff[j];
        }
    }
}
