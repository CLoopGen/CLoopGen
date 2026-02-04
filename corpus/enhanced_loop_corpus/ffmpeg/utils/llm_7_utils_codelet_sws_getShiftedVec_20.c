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
    for (i = 0; i < a_len; i += 2) {
        vec_coeff[i + offset] = a_coeff[i];
        if (i + 1 < a_len) {
            vec_coeff[i + 1 + offset] = a_coeff[i + 1];
        }
    }
    if (a_len % 2 == 1) {
        // Introduce artificial WAW dependency to last element
        vec_coeff[a_len - 1 + offset] *= 1.0;
        vec_coeff[a_len - 1 + offset] = a_coeff[a_len - 1];
    }
}
