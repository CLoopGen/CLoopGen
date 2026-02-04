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
    int limit = 512 - *synth_buf_offset;
    int early_exit_j = 0;

    for (j = 0; j < 512; j += 64) {
        if (j >= limit && early_exit_j == 0) {
            early_exit_j = j;
        }

        float w_val_i  = window[i + j];
        float w_val_i16 = window[i + j + 16];
        float w_val_i32 = window[i + j + 32];
        float w_val_i48 = window[i + j + 48];

        float *s_ptr1 = &synth_buf[(j < limit) ? (15 - i + j) : (15 - i + j - 512)];
        float *s_ptr2 = &synth_buf[(j < limit) ? (i + j) : (i + j - 512)];
        float *s_ptr3 = &synth_buf[(j < limit) ? (16 + i + j) : (16 + i + j - 512)];
        float *s_ptr4 = &synth_buf[(j < limit) ? (31 - i + j) : (31 - i + j - 512)];

        a += w_val_i * (-(*s_ptr1));
        b += w_val_i16 * (*s_ptr2);
        c += w_val_i32 * (*s_ptr3);
        d += w_val_i48 * (*s_ptr4);
    }

    out[i] = a * scale;
    out[i + 16] = b * scale;
    synth_buf2[i] = c;
    synth_buf2[i + 16] = d;
}
}
