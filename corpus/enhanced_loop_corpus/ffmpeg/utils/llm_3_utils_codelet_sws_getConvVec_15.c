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
    // Variant 2: Consecutive memory access by transposing the iteration order to improve spatial locality
    // We reverse the loop nesting and accumulate into a temporary buffer to enable sequential writes
    int len_a = a->length;
    int len_b = b->length;
    int total_len = len_a + len_b - 1;

    // Temporary buffer to allow sequential accumulation
    double *temp = (double*)calloc(total_len, sizeof(double));

    for (j = 0; j < len_b; j++) {
        double b_coeff_j = b->coeff[j];  // Load once for reuse
        for (i = 0; i < len_a; i++) {
            temp[i + j] += a->coeff[i] * b_coeff_j;
        }
    }

    // Sequential write back to vec->coeff
    for (i = 0; i < total_len; i++) {
        vec->coeff[i] += temp[i];
    }

    free(temp);
}
