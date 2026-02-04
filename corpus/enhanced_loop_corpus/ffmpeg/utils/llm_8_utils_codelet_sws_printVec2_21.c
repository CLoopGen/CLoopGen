#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern int i;
extern double max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < a->length; i += stride) {
        if (a->coeff[i] > max)
            max = a->coeff[i];
    }
    // Handle any remaining element if length is odd
    if (a->length % 2 == 1 && a->coeff[a->length - 1] > max)
        max = a->coeff[a->length - 1];
}
