#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *second_derivative;
extern short *crossings;
extern ssize_t i;
extern ssize_t parity;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (forward and backward fill)
    ssize_t stride = 2;
    parity = (parity < 0) ? -1 : 1; // Normalize parity

    // Forward pass: even indices
    for (i = 0; i <= 255; i += stride) {
        crossings[i] = 0;
        if (second_derivative[i] < 0.) {
            if (parity > 0)
                crossings[i] = (-1);
            parity = 1;
        } else if (second_derivative[i] > 0.) {
            if (parity < 0)
                crossings[i] = 1;
            parity = (-1);
        }
    }

    // Backward pass: odd indices
    for (i = 255 - ((255 % stride) == 0 ? 1 : 0); i >= 1; i -= stride) {
        ssize_t idx = i - 1; // Access odd index
        crossings[idx] = 0;
        if (second_derivative[idx] < 0.) {
            if (parity > 0)
                crossings[idx] = (-1);
            parity = 1;
        } else if (second_derivative[idx] > 0.) {
            if (parity < 0)
                crossings[idx] = 1;
            parity = (-1);
        }
    }
}
