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
    int total_len = a->length + b->length - 1;
    double *temp = (double*)calloc(total_len, sizeof(double));
    for (i = 0; i < a->length; i++) {
        for (j = 0; j < b->length; j++) {
            temp[i + j] += a->coeff[i] * b->coeff[j];
        }
    }
    for (i = 0; i < total_len; i++) {
        vec->coeff[i] = temp[i];
    }
    free(temp);
}
