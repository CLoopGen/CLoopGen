#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define DATA_SIZE_MB 64
#define TOTAL_SAMPLES (DATA_SIZE_MB * 1024 * 1024 / sizeof(short))
#define NSAMPLES (TOTAL_SAMPLES / 2)

short buffer[TOTAL_SAMPLES];
int nsamples = NSAMPLES;
int i;

short *buffer_l;
short *buffer_r;

void init_vars() {
    buffer_l = (short*)malloc(nsamples * sizeof(short));
    buffer_r = (short*)malloc(nsamples * sizeof(short));

    for (int idx = 0; idx < TOTAL_SAMPLES; idx++) {
        buffer[idx] = (short)(idx & 0xFFFF);
    }
}