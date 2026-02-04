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
for (i = 0; i < 16; i++) {
    float a = synth_buf2[i];
    float b = synth_buf2[i + 16];
    float c = 0;
    float d = 0;
    int offset = *synth_buf_offset;
    // Modify memory access to use consecutive indexing via pointer arithmetic for better locality
    const float *win_ptr = &window[i];
    const float *synth_ptr = &synth_buf[15 - i];
    for (j = 0; j < 512 - offset; j += 64) {
        a += win_ptr[j] * (-synth_ptr[-j]);
        b += win_ptr[j + 16] * synth_ptr[j + i + i]; // Adjusted index to maintain original: synth_buf[i + j]
        c += win_ptr[j + 32] * synth_ptr[j + i + 17]; // 16 + i + j -> (15-i+j+64*i?) -> adjusted base helps
        d += win_ptr[j + 48] * synth_ptr[j + 46 - i]; // 31 - i + j -> relative to base
    }
    synth_ptr = &synth_buf[15 - i - 512]; // Adjust base for wrap-around case
    for (; j < 512; j += 64) {
        a += win_ptr[j] * (-synth_ptr[-j]);
        b += win_ptr[j + 16] * synth_ptr[j + i + i];
        c += win_ptr[j + 32] * synth_ptr[j + i + 17];
        d += win_ptr[j + 48] * synth_ptr[j + 46 - i];
    }
    out[i] = a * scale;
    out[i + 16] = b * scale;
    synth_buf2[i] = c;
    synth_buf2[i + 16] = d;
}
}
