#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float synth_buf2[32];
float window[512];
float out[32];
float scale;
float *synth_buf;
int *synth_buf_offset;
int i;
int j;

static float internal_synth_buf_data[1024];
static int internal_synth_buf_offset = 0;

void init_vars() {
    for (int idx = 0; idx < 32; idx++) {
        synth_buf2[idx] = 0.1f * idx;
        out[idx] = 0.0f;
    }
    for (int idx = 0; idx < 512; idx++) {
        window[idx] = 0.5f + 0.5f * (idx % 2);
    }
    scale = 0.0625f;
    synth_buf = internal_synth_buf_data;
    synth_buf_offset = &internal_synth_buf_offset;

    for (int idx = 0; idx < 1024; idx++) {
        internal_synth_buf_data[idx] = 0.01f * (idx % 64);
    }
}