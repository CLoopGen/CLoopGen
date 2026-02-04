#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out_data;
float *synth;
float *tmpbuf;
float s;
int i;

#define DATA_SIZE 30

void init_vars() {
    out_data = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    synth = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    tmpbuf = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));

    for (int j = 0; j < DATA_SIZE; j++) {
        out_data[j] = 0.0f;
        synth[j] = (float)(j * 2);
        tmpbuf[j] = (float)j;
    }
}