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
    for (i = 0; i < a->length; i++) {
        double val = a->coeff[i];
        if (!(val >= min)) {
            min = val;
        }
    }
}
