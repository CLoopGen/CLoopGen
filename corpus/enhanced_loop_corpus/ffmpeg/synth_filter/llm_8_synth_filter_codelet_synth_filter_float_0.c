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
    for (j = 0; j < 512 - *synth_buf_offset; j += 32) {
        a += window[i + j] * (-synth_buf[15 - i + j]);
        a += window[i + j + 32] * (-synth_buf[15 - i + j + 32]);
        b += window[i + j + 16] * (synth_buf[i + j]);
        b += window[i + j + 48] * (synth_buf[i + j + 32]);
        c += window[i + j + 32] * (synth_buf[16 + i + j]);
        c += window[i + j + 64] * (synth_buf[16 + i + j + 32]);
        d += window[i + j + 48] * (synth_buf[31 - i + j]);
        d += window[i + j + 80] * (synth_buf[31 - i + j + 32]);
    }
    for (; j < 512; j += 32) {
        a += window[i + j] * (-synth_buf[15 - i + j - 512]);
        a += window[i + j + 32] * (-synth_buf[15 - i + j + 32 - 512]);
        b += window[i + j + 16] * (synth_buf[i + j - 512]);
        b += window[i + j + 48] * (synth_buf[i + j + 32 - 512]);
        c += window[i + j + 32] * (synth_buf[16 + i + j - 512]);
        c += window[i + j + 64] * (synth_buf[16 + i + j + 32 - 512]);
        d += window[i + j + 48] * (synth_buf[31 - i + j - 512]);
        d += window[i + j + 80] * (synth_buf[31 - i + j + 32 - 512]);
    }
    out[i] = a * scale;
    out[i + 16] = b * scale;
    synth_buf2[i] = c;
    synth_buf2[i + 16] = d;
}
}
