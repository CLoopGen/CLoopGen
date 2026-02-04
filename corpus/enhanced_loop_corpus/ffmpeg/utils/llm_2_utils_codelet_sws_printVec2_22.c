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
extern double min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < a->length; i += stride)
        if (a->coeff[i] < min)
            min = a->coeff[i];
    for (i = 1; i < a->length; i += stride)
        if (a->coeff[i] < min)
            min = a->coeff[i];
}
