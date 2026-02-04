#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **samples;
extern float **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern float v0;
extern float v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access Pattern with Loop Interchange Attempt (within constraints)
    // Restructure data access to improve spatial locality by reorganizing how samples are accessed.
    // Since full interchange isn't feasible due to reduction in j, we optimize inner-loop memory access
    // by ensuring consecutive reads from matrix while traversing samples in a cache-friendly manner.
    // We reverse loop order conceptually but preserve correctness using temporary accumulators.

    float *sample_val;
    float m0j, m1j;

    for (i = 0; i < len; i++) {
        v0 = v1 = 0.F;
        for (j = 0; j < in_ch; j++) {
            // Access matrix elements consecutively: [0][j], [1][j]
            m0j = matrix[0][j];
            m1j = matrix[1][j];
            sample_val = samples[j];  // Base of j-th channel
            v0 += sample_val[i] * m0j;
            v1 += sample_val[i] * m1j;
        }
        samples[0][i] = v0;
        samples[1][i] = v1;
    }
}
