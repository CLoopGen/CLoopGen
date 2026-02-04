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
    double *coeff_ptr = a->coeff;
    int len = a->length;
    for (i = 0; i < len; i++) {
        sum = sum + coeff_ptr[i] * 1.0;
    }
}
