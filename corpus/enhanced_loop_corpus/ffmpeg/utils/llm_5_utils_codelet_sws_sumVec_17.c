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
    for (i = 0; i < b->length && b->length > 0; i++) {
        int offset = (length - 1) / 2 - (b->length - 1) / 2;
        int target_index = i + offset;
        if (target_index >= 0 && target_index < length) {
            vec->coeff[target_index] += b->coeff[i];
        }
    }
}
