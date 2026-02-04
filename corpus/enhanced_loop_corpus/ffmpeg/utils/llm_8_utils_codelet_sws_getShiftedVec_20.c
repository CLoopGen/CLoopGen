#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern int shift;
extern int length;
extern int i;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (length - 1) / 2 - (a->length - 1) / 2 - shift;
    for (i = 0; i < a->length; i += 2) {
        vec->coeff[i + start] = a->coeff[i];
        if (i + 1 < a->length) {
            vec->coeff[i + 1 + start] = a->coeff[i + 1];
        }
    }
}
