#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *samples;
extern  float *coeff;
extern int nsamples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // We simulate indirect access by using precomputed effective indices through a lookup pattern.
    // Instead of direct (i - j - 1), use a shuffled offset pattern to mimic irregular access.
    int offsets[8] = {0, -2, -1, -6, -3, -7, -4, -5}; // Custom indirect-like access pattern
    for (i = 0; i < nsamples; i++) {
        float res = 0;
        for (j = 0; j < 8; j++) {
            int idx = i + offsets[j]; // Indirect-style indexing
            if (idx >= 0) {
                res += coeff[j] * samples[idx];
            }
        }
        samples[i] -= res;
    }
}
