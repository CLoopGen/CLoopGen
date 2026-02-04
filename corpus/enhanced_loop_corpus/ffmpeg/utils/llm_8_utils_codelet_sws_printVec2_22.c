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



void loop() {
    int i = 0;
    double min_val = min;
    int len = a->length;
    
    // Unroll the loop by a factor of 4 to reduce branch overhead and increase computational intensity
    for (; i <= len - 4; i += 4) {
        if (a->coeff[i] < min_val)
            min_val = a->coeff[i];
        if (a->coeff[i+1] < min_val)
            min_val = a->coeff[i+1];
        if (a->coeff[i+2] < min_val)
            min_val = a->coeff[i+2];
        if (a->coeff[i+3] < min_val)
            min_val = a->coeff[i+3];
    }
    // Handle remaining elements
    for (; i < len; i++) {
        if (a->coeff[i] < min_val)
            min_val = a->coeff[i];
    }
    min = min_val;
}
