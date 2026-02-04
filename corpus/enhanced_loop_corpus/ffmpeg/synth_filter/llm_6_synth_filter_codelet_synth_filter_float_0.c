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
    for (j = 0; j < 512 - offset; j += 64) {
        float win_i_j = window[i + j];
        float win_i_j_16 = window[i + j + 16];
        float win_i_j_32 = window[i + j + 32];
        float win_i_j_48 = window[i + j + 48];
        float buf_val1 = -synth_buf[15 - i + j];
        float buf_val2 = synth_buf[i + j];
        float buf_val3 = synth_buf[16 + i + j];
        float buf_val4 = synth_buf[31 - i + j];

        a += win_i_j * buf_val1;
        b += win_i_j_16 * buf_val2;
        c += win_i_j_32 * buf_val3;
        d += win_i_j_48 * buf_val4;
    }
    for (; j < 512; j += 64) {
        int adjusted_j = j - 512;
        a += window[i + j] * (-synth_buf[15 - i + adjusted_j]);
        b += window[i + j + 16] * (synth_buf[i + adjusted_j]);
        c += window[i + j + 32] * (synth_buf[16 + i + adjusted_j]);
        d += window[i + j + 48] * (synth_buf[31 - i + adjusted_j]);
    }
    out[i] = a * scale;
    out[i + 16] = b * scale;
    synth_buf2[i] = c;
    synth_buf2[i + 16] = d;
}
}
