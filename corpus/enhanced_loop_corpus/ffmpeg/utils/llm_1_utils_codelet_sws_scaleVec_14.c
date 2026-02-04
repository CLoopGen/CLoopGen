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
    if (a->length > 0) {
        i = 0;
        for (; i < a->length; ) {
            a->coeff[i] *= scalar;
            i++;
        }
    }
}
