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
    int start = (length - 1) / 2 - (a->length - 1) / 2;
    for (i = 0; i < a->length; i += 2) {
        if (i + 1 < a->length) {
            vec->coeff[i + start] += a->coeff[i];
            vec->coeff[i + 1 + start] += a->coeff[i + 1];
        } else {
            vec->coeff[i + start] += a->coeff[i];
        }
    }
}
