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
    int start = (length - 1) / 2 - (b->length - 1) / 2;
    for (i = 0; i < b->length; i += 2) {
        if (i + 1 < b->length) {
            vec->coeff[start + i] += b->coeff[i];
            vec->coeff[start + i + 1] += b->coeff[i + 1];
        } else {
            vec->coeff[start + i] += b->coeff[i];
        }
    }
}
