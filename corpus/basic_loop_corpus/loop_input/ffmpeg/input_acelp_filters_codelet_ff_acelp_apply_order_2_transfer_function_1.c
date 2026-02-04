#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
float *in;
float zero_coeffs[2];
float pole_coeffs[2];
float gain;
float mem[2];
int n;
int i;
float tmp;

void init_vars() {
    n = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime

    in = (float*)malloc(n * sizeof(float));
    out = (float*)malloc(n * sizeof(float));

    for (int j = 0; j < n; j++) {
        in[j] = (float)(j % 1000) / 1000.0f;
    }

    zero_coeffs[0] = 0.5f;
    zero_coeffs[1] = 0.25f;
    pole_coeffs[0] = 0.3f;
    pole_coeffs[1] = 0.1f;
    gain = 1.5f;

    mem[0] = 0.0f;
    mem[1] = 0.0f;

    i = 0;
    tmp = 0.0f;
}