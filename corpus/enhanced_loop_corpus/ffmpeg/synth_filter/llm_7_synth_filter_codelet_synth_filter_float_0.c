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
    float temp_out1, temp_out2;
    float c = 0, d = 0;
    float a = synth_buf2[i];
    float b = synth_buf2[i + 16];

    int offset = *synth_buf_offset;
    int limit = 512 - offset;

    for (j = 0; j < limit; j += 64) {
        int idx = i + j;
        a += window[idx] * (-synth_buf[15 - i + j]);
        b += window[idx + 16] * synth_buf[i + j];
        c += window[idx + 32] * synth_buf[16 + i + j];
        d += window[idx + 48] * synth_buf[31 - i + j];
    }

    for (; j < 512; j += 64) {
        int idx = i + j;
        int prev = j - 512;
        a += window[idx] * (-synth_buf[15 - i + prev]);
        b += window[idx + 16] * synth_buf[i + prev];
        c += window[idx + 32] * synth_buf[16 + i + prev];
        d += window[idx + 48] * synth_buf[31 - i + prev];
    }

    temp_out1 = a * scale;
    temp_out2 = b * scale;

    synth_buf2[i] = c;
    synth_buf2[i + 16] = d;
    out[i] = temp_out1;
    out[i + 16] = temp_out2;
}
}
