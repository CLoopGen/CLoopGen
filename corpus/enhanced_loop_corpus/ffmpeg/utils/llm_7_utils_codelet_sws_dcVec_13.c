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
    double prev = 0.0;
    for (i = 0; i < a->length; i++) {
        double current = a->coeff[i] + prev;
        prev = current;
        sum += current;
    }
}
