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
    // Variant 2: Strided memory access (stride of 2, wrapping with modulo to stay in bounds)
    int base_offset = (length - 1) / 2 - (a->length - 1) / 2;
    int stride = 2;
    int n = a->length;
    for (i = 0; i < n; i += stride) {
        int j = i;
        int vec_idx = (base_offset + j) % vec->length;
        if (vec_idx >= 0 && vec_idx < vec->length)
            vec->coeff[vec_idx] += a->coeff[j];
        // Handle second element in stride if within bounds
        j = i + 1;
        if (j < n) {
            vec_idx = (base_offset + j) % vec->length;
            if (vec_idx >= 0 && vec_idx < vec->length)
                vec->coeff[vec_idx] += a->coeff[j];
        }
    }
    // Final pass for any remaining index if original loop had odd length
    if (a->length % 2 == 1) {
        i = a->length - 1;
        int vec_idx = (base_offset + i);
        if (vec_idx >= 0 && vec_idx < vec->length)
            vec->coeff[vec_idx] += a->coeff[i];
    }
}
