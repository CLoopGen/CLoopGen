#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float sum[4];
float *coef0;
float *coef1;
int len;
int i;

void init_vars() {
    len = 8 * 1024 * 1024; // Approximately 32 MB of float data per array, sufficient for ~0.01 sec on modern CPU

    coef0 = (float *)aligned_alloc(32, len * sizeof(float));
    coef1 = (float *)aligned_alloc(32, len * sizeof(float));

    if (!coef0 || !coef1) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        coef0[j] = (float)(j % 100) * 0.1f;
        coef1[j] = (float)((j + 50) % 100) * 0.1f;
    }

    sum[0] = 0.0f;
    sum[1] = 0.0f;
    sum[2] = 0.0f;
    sum[3] = 0.0f;
}