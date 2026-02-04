#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (unrolling-like pattern)
    // Accesses every other element in a forward and mirrored backward fashion
    for (k = 0; k < n4; k += 2) {
        if (k + 1 < n4) {
            // Process two elements at once with stride 2
            output[k]     = -output[n2 - k     - 1];
            output[k + 1] = -output[n2 - k - 2 - 1];

            output[n - k - 1]         = output[n2 + k];
            output[n - (k + 1) - 1]   = output[n2 + k + 1];
        } else {
            // Handle remaining single element if n4 is odd
            output[k] = -output[n2 - k - 1];
            output[n - k - 1] = output[n2 + k];
        }
    }
}
