#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define TOTAL_FLOATS (DATA_SIZE_MB * 1024 * 1024 / sizeof(float))

static float Y_data[TOTAL_FLOATS];
void *Y = Y_data;
int incY = 1;
int i = 0;
int lenY = 0;
float beta_real = 1.5f;
float beta_imag = 0.8f;
int iy = 0;

void init_vars() {
    const size_t complex_elements = TOTAL_FLOATS / 2;
    lenY = (int)(complex_elements > 1000000 ? 1000000 : complex_elements - 1);
    iy = 0;
    beta_real = 1.23f;
    beta_imag = -0.45f;
    incY = 1;

    for (size_t idx = 0; idx < TOTAL_FLOATS; ++idx) {
        Y_data[idx] = (float)(idx % 128) * 0.1f;
    }
}