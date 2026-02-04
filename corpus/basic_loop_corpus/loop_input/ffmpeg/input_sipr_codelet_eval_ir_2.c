#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

const float ff_pow_0_7[10] = {
    1.0f,
    0.7f,
    0.49f,
    0.343f,
    0.2401f,
    0.16807f,
    0.117649f,
    0.0823543f,
    0.057648f,
    0.0403536f
};

const float ff_pow_0_55[10] = {
    1.0f,
    0.55f,
    0.3025f,
    0.166375f,
    0.09150625f,
    0.0503284375f,
    0.0276806406f,
    0.0152243523f,
    0.0083733938f,
    0.0046053666f
};

float *Az;
float tmp1[49];
float tmp2[11];
int i;

void init_vars() {
    const size_t data_size = 1 << 20;
    Az = (float *)aligned_alloc(32, data_size * sizeof(float));
    if (!Az) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; idx++) {
        Az[idx] = (float)(idx % 100) * 0.01f;
    }
}