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
    int offset = (length - 1) / 2 - (b->length - 1) / 2;
    int trip_count = b->length * 3;
    for (i = 0; i < trip_count; i++) {
        int j = i % b->length;
        vec->coeff[offset + j] -= b->coeff[j] * 0.5;
    }
}
