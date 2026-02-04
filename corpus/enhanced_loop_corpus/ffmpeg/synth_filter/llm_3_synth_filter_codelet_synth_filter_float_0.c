#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *synth_buf_offset;
extern float synth_buf2[32];
extern  float window[512];
extern float out[32];
extern float scale;
extern float *synth_buf;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change to strided memory access pattern with reversed inner loop traversal
// Use precomputed indices in a strided manner to increase stride and test different access behavior
for (i = 0; i < 16; i++) {
    float a = synth_buf2[i];
    float b = synth_buf2[i + 16];
    float c = 0;
    float d = 0;
    int offset = *synth_buf_offset;
    // Process the inner loop using fixed stride but reverse the order of j-blocks
    // Simulate strided access by jumping in large steps, then adjust within blocks
    for (j = (512 - offset) % 64; j < 512 - offset; j += 64) {
        int idx = 511 - j; // Reverse access pattern across window
        a += window[i + idx] * (-synth_buf[15 - i + idx]);
        b += window[i + idx + 16] * synth_buf[i + idx];
        c += window[i + idx + 32] * synth_buf[16 + i + idx];
        d += window[i + idx + 48] * synth_buf[31 - i + idx];
    }
    for (; (j % 64) != 0; j += 64) { // Complete remaining blocks after offset boundary
        int idx = 511 - j;
        a += window[i + idx] * (-synth_buf[15 - i + idx - 512]);
        b += window[i + idx + 16] * synth_buf[i + idx - 512];
        c += window[i + idx + 32] * synth_buf[16 + i + idx - 512];
        d += window[i + idx + 48] * synth_buf[31 - i + idx - 512];
    }
    out[i] = a * scale;
    out[i + 16] = b * scale;
    synth_buf2[i] = c;
    synth_buf2[i + 16] = d;
}
}
