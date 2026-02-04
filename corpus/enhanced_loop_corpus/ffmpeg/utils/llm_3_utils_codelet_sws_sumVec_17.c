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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    int len = b->length;
    int offset = (length - 1) / 2 - (len - 1) / 2;
    int i;

    for (i = len - 1; i >= 0; i--)
        vec->coeff[i + offset] += b->coeff[i];
}
