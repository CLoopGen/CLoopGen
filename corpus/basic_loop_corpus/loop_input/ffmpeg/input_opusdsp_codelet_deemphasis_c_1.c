#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *y;
float *x;
float coeff;
int len;

void init_vars() {
    len = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime

    x = (float*)malloc(len * sizeof(float));
    y = (float*)malloc(len * sizeof(float));

    if (!x || !y) {
        // In case malloc fails, avoid undefined behavior
        exit(1);
    }

    coeff = 1.0f;

    for (int i = 0; i < len; i++) {
        x[i] = 1.0f / (i + 1); // Avoid division by zero
        y[i] = 0.0f;
    }
}