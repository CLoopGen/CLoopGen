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
extern double max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_max = max;
    for (i = 0; i < a->length; i++) {
        if (a->coeff[i] > temp_max)
            temp_max = a->coeff[i];
    }
    max = temp_max;
}
