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
// Flatten potential nesting by ensuring single-level loop, but simulate deeper logic with conditional steps
int stride = 1;
for (i = 0; i < a->length; i += stride)
    if (a->coeff[i] > max)
        max = a->coeff[i];
}
