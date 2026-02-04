#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *input;
extern int order;
extern int size;
extern double *output;
extern double scale;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reverse loop iteration order to change direction of loop-carried dependencies
    // Introduce artificial dependency using a running accumulator that affects scaling
    double acc = 1.0;
    for (i = order; i >= 0; i--) { // Reversed loop bounds
        double value = 0.;
        for (j = i; j < size; j++) {
            value += input[j] * input[j - i];
        }
        // Introduce dependency on previous iteration's scaled result via 'acc'
        double scaled_value = value * scale * acc;
        output[i] = scaled_value;
        acc = scaled_value + 1e-9; // Create loop-carried flow dependency (RAW) from current to next (previous in index)
    }
}
