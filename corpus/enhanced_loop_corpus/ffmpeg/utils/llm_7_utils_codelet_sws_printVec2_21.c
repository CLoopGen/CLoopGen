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
    double local_max = -__builtin_huge_val();
    int stride = 2;
    for (i = 0; i < a->length - (a->length % stride); i += stride) {
        double val1 = a->coeff[i];
        double val2 = a->coeff[i + 1];
        double cmp1 = (val1 > val2) ? val1 : val2;
        local_max = (cmp1 > local_max) ? cmp1 : local_max;
    }
    for (; i < a->length; i++) {
        if (a->coeff[i] > local_max)
            local_max = a->coeff[i];
    }
    if (local_max > max)
        max = local_max;
}
