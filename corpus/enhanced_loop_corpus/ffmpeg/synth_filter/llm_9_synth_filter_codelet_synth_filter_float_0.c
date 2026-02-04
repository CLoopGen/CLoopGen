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
for (i = 0; i < 8; i++) {
    float a0 = synth_buf2[i];
    float a1 = synth_buf2[i + 8];
    float b0 = synth_buf2[i + 16];
    float b1 = synth_buf2[i + 24];
    float c0 = 0, c1 = 0;
    float d0 = 0, d1 = 0;
    for (j = 0; j < 512 - *synth_buf_offset; j += 64) {
        int idx = i + j;
        a0 += window[idx] * (-synth_buf[15 - i + j]);
        a1 += window[idx + 8] * (-synth_buf[7 - i + j]);
        b0 += window[idx + 16] * (synth_buf[i + j]);
        b1 += window[idx + 24] * (synth_buf[i + 8 + j]);
        c0 += window[idx + 32] * (synth_buf[16 + i + j]);
        c1 += window[idx + 40] * (synth_buf[24 + i + j]);
        d0 += window[idx + 48] * (synth_buf[31 - i + j]);
        d1 += window[idx + 56] * (synth_buf[23 - i + j]);
    }
    for (; j < 512; j += 64) {
        int idx = i + j;
        a0 += window[idx] * (-synth_buf[15 - i + j - 512]);
        a1 += window[idx + 8] * (-synth_buf[7 - i + j - 512]);
        b0 += window[idx + 16] * (synth_buf[i + j - 512]);
        b1 += window[idx + 24] * (synth_buf[i + 8 + j - 512]);
        c0 += window[idx + 32] * (synth_buf[16 + i + j - 512]);
        c1 += window[idx + 40] * (synth_buf[24 + i + j - 512]);
        d0 += window[idx + 48] * (synth_buf[31 - i + j - 512]);
        d1 += window[idx + 56] * (synth_buf[23 - i + j - 512]);
    }
    out[i] = a0 * scale;
    out[i + 8] = a1 * scale;
    out[i + 16] = b0 * scale;
    out[i + 24] = b1 * scale;
    synth_buf2[i] = c0;
    synth_buf2[i + 8] = c1;
    synth_buf2[i + 16] = d0;
    synth_buf2[i + 24] = d1;
}
}
