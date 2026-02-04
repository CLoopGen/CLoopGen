#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern double c;
extern int length;
extern int i;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < length; i += 2) {
        vec->coeff[i] = c * 2.0;
        if (i + 1 < length) {
            vec->coeff[i + 1] = c * 3.0;
        }
    }
}
