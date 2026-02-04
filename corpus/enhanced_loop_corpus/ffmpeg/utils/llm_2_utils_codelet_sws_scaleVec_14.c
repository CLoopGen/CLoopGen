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
    int len = a->length;
    double *coeff = a->coeff;
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            coeff[i] *= scalar;
            coeff[i + 1] *= scalar;
        } else {
            coeff[i] *= scalar;
        }
    }
}
