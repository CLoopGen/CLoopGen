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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            a->coeff[i] *= scalar;
            a->coeff[i + 1] *= scalar;
        } else {
            a->coeff[i] *= scalar;
        }
    }
}
