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
    for (i = 0; i < b->length; i++) {
        int index = i + (length - 1) / 2 - (b->length - 1) / 2;
        if (index >= 0) {
            vec->coeff[index] -= b->coeff[i];
        }
    }
}
