#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *y;
int len;
float Syy;

void init_vars() {
    len = 1 << 20; // Approximately 1 million elements for ~0.01 sec on modern CPU
    y = (float *)aligned_alloc(32, len * sizeof(float));
    if (!y) {
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        y[i] = (float)(i % 1000) / 100.0f;
    }
    Syy = 0.0f;
}