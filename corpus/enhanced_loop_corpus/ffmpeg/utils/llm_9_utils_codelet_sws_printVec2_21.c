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
    double local_max1 = -__builtin_huge_val(), local_max2 = -__builtin_huge_val();
    int j;
    for (i = 0; i < a->length - 1; i += 2) {
        if (a->coeff[i] > local_max1)
            local_max1 = a->coeff[i];
        if (a->coeff[i + 1] > local_max2)
            local_max2 = a->coeff[i + 1];
    }
    // Handle last element if length is odd
    if (i == a->length - 1) {
        if (a->coeff[i] > local_max1)
            local_max1 = a->coeff[i];
    }
    max = (local_max1 > local_max2) ? local_max1 : local_max2;
}
