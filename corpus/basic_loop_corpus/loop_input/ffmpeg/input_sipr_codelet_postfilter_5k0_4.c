#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const float ff_pow_0_75[10] = {
    1.0f, 0.5946f, 0.4422f, 0.3482f, 0.2842f, 0.2381f, 0.2031f, 0.1758f, 0.1539f, 0.1361f
};

const float ff_pow_0_5[16] = {
    1.0f, 0.7071f, 0.5f, 0.3536f, 0.25f, 0.1768f, 0.125f, 0.0884f,
    0.0625f, 0.0442f, 0.03125f, 0.0221f, 0.015625f, 0.01107f, 0.0078125f, 0.00552f
};

float *lpc;
float lpc_n[10];
float lpc_d[10];
int i;

static float *lpc_data = NULL;

void init_vars() {
    lpc_data = (float *)aligned_alloc(32, 16 * sizeof(float));
    if (!lpc_data) {
        exit(1);
    }
    for (int j = 0; j < 10; j++) {
        lpc_data[j] = 1.0f + j * 0.5f;
    }
    lpc = lpc_data;
}