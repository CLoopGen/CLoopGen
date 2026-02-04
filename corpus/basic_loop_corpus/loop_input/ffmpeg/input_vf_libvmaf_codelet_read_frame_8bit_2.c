#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int stride;
int main_stride;
uint8_t *main_ptr;
float *ptr;
float factor;
int h;
int w;
int i;
int j;

static uint8_t *main_data;
static float *float_data;

void init_vars() {
    factor = 1.5f;
    h = 2048;
    w = 2048;
    stride = w * sizeof(float);
    main_stride = w * sizeof(uint8_t);

    size_t main_size = (size_t)h * w * sizeof(uint8_t);
    size_t float_size = (size_t)h * w * sizeof(float);

    main_data = aligned_alloc(32, main_size);
    float_data = aligned_alloc(32, float_size);

    if (!main_data || !float_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t k = 0; k < h * w; k++) {
        main_data[k] = (uint8_t)(k % 256);
    }
    for (size_t k = 0; k < h * w; k++) {
        float_data[k] = 0.0f;
    }

    main_ptr = main_data;
    ptr = float_data;
}