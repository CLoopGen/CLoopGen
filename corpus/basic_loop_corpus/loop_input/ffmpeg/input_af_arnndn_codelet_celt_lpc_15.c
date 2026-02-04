#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *lpc;
float *ac;
int p;
float r;
float error;

void init_vars() {
    p = 1000;
    r = 0.5F;
    error = 1.0F;

    lpc = (float*)calloc(p, sizeof(float));
    ac = (float*)calloc(p + 1, sizeof(float));

    for (int i = 0; i <= p; i++) {
        ac[i] = 1.0F / (1.0F + i);
    }

    for (int i = 0; i < p; i++) {
        lpc[i] = 0.0F;
    }
}