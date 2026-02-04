#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern float *prev;
extern int num_samples;
extern float *out;
extern float gc_scale;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer, inner;
    const int block_size = 16;
    for (outer = 0; outer < num_samples; outer += block_size) {
        for (inner = 0; inner < block_size && (outer + inner) < num_samples; inner++) {
            int pos = outer + inner;
            out[pos] = in[pos] * gc_scale + prev[pos];
        }
    }
}
