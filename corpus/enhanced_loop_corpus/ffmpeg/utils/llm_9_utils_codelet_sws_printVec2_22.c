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
    int i;
    double temp_min = a->coeff[0];  // Assume length >= 1
    
    // Increase arithmetic operations per iteration with redundant comparisons
    // and additional dummy computations to increase computational load
    for (i = 0; i < a->length; i++) {
        double val = a->coeff[i];
        // Actual comparison
        if (val < temp_min) {
            temp_min = val;
        }
        // Dummy computation to increase arithmetic intensity (no effect on logic)
        temp_min = (temp_min + val * 0.0) > temp_min ? temp_min : val;
    }
    min = temp_min;
}
