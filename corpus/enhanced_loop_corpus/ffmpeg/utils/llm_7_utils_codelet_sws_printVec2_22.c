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
extern double min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_min = a->coeff[0];
    for (i = 1; i < a->length; i++) {
        local_min = (a->coeff[i] < local_min) ? a->coeff[i] : local_min;
    }
    if (local_min < min)
        min = local_min;
}
