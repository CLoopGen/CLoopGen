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
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    int len_a = a->length;
    int len_b = b->length;
    int vec_len = len_a + len_b - 1;

    // Process even indices with stride 2
    for (i = 0; i < len_a; i += 2) {
        for (j = 0; j < len_b; j += 2) {
            if (i + j < vec_len) {
                vec->coeff[i + j] += a->coeff[i] * b->coeff[j];
            }
        }
    }
    // Process odd indices with offset and stride 2
    for (i = 1; i < len_a; i += 2) {
        for (j = 1; j < len_b; j += 2) {
            if (i + j < vec_len) {
                vec->coeff[i + j] += a->coeff[i] * b->coeff[j];
            }
        }
    }
}
