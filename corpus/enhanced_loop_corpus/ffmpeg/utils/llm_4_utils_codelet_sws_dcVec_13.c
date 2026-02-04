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
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0;
    for (i = 0; i < a->length; i++) {
        if (a->coeff[i] > 0) {
            sum += a->coeff[i];
        }
    }
}
