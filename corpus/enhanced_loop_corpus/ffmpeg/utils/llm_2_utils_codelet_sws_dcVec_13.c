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
    int len = a->length;
    double *coeff = a->coeff;
    for (i = 0; i < len; i += 2) {
        sum += coeff[i];
        if (i + 1 < len) {
            sum += coeff[i + 1];
        }
    }
}
