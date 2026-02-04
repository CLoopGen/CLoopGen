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
    double s = scalar;
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            coeff[i] *= s;
            coeff[i + 1] *= s;
        } else {
            coeff[i] *= s;
        }
    }
}
