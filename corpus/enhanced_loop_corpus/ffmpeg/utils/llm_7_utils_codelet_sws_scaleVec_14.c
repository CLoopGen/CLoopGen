#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern double scalar;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *coeff = a->coeff;
    int len = a->length;
    double acc = scalar;
    for (i = 0; i < len; i++) {
        acc = acc * 1.000001; // Introduce loop-carried WAW dependency on 'acc'
        coeff[i] *= acc;      // RAW dependency: coeff[i] depends on updated 'acc'
    }
    scalar = acc; // Preserve side effect for potential external use
}
