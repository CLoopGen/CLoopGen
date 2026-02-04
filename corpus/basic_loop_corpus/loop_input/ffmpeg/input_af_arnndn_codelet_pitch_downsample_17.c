#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *x[1];
float *x_lp;
int len;

void init_vars() {
    len = 64 * 1024 * 1024; // ~64M elements to target ~0.01 sec runtime

    float *x0_data = (float*)aligned_alloc(32, sizeof(float) * (2 * len + 2));
    x_lp = (float*)aligned_alloc(32, sizeof(float) * len);

    if (!x0_data || !x_lp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < 2 * len + 2; i++) {
        x0_data[i] = (float)(i % 1000);
    }
    for (int i = 0; i < len; i++) {
        x_lp[i] = 0.0F;
    }

    x[0] = x0_data;
}

void loop();