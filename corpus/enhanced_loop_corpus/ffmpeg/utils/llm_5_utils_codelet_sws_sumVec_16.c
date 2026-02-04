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
    int offset = (length - 1) / 2 - (a->length - 1) / 2;
    for (i = 0; i < a->length; i++) {
        if (a->coeff[i] != 0.0) {
            vec->coeff[i + offset] += a->coeff[i];
        }
    }
}
