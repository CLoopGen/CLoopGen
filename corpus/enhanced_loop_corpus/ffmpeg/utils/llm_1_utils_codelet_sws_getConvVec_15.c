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
    int n = a->length + b->length - 1;
    for (int k = 0; k < n; k++) {
        double sum = 0.0;
        int start_i = (k >= b->length) ? k - b->length + 1 : 0;
        int end_i = (k < a->length) ? k + 1 : a->length;
        for (i = start_i; i < end_i; i++) {
            j = k - i;
            if (j >= 0 && j < b->length) {
                sum += a->coeff[i] * b->coeff[j];
            }
        }
        vec->coeff[k] += sum;
    }
}
