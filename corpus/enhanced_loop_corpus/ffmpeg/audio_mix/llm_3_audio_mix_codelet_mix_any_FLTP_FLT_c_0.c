#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **samples;
extern float **matrix;
extern int len;
extern int out_ch;
extern int in_ch;
extern int i;
extern int in;
extern int out;
extern float temp[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Transpose the loop nest: iterate over in_ch first, then len, then out_ch
// This changes memory access to be more sequential in 'samples' and 'matrix' across inner loops
for (in = 0; in < in_ch; in++) {
    for (i = 0; i < len; i++) {
        float sample_val = samples[in][i];
        for (out = 0; out < out_ch; out++) {
            // Accumulate using a strided access on matrix: each out accesses same row, consecutive columns
            if (in == 0) temp[out] = 0; // Reset accumulator at start of in=0
            temp[out] += sample_val * matrix[out][in];
            // Final accumulation writeback delayed until last in_ch iteration
            if (in == in_ch - 1)
                samples[out][i] = temp[out];
        }
    }
}
}
