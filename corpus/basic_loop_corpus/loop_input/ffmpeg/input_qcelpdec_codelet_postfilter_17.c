#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 10

float *lpc;
float pow_0_775[10];
float pow_0_625[10];
float lpc_s[10];
float lpc_p[10];
int n;

void init_vars() {
    lpc = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    if (!lpc) exit(1);

    for (int i = 0; i < DATA_SIZE; i++) {
        lpc[i] = 1.0f + (i * 0.1f);
        pow_0_775[i] = 0.775f;
        pow_0_625[i] = 0.625f;
        lpc_s[i] = 0.0f;
        lpc_p[i] = 0.0f;
    }
}