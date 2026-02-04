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
    int stride = 2;
    int n = a->length;
    for (i = 0; i < n; i += stride) {
        if (a->coeff[i] > max)
            max = a->coeff[i];
    }
    // Handle any odd-length array by checking the last element if stride skips it
    if (n % stride != 0 && (n - 1) > 0) {
        i = n - 1;
        if (a->coeff[i] > max)
            max = a->coeff[i];
    }
}
