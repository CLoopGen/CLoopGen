#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride;
int main_stride;
uint16_t *main_ptr;
float *ptr;
float factor;
int h;
int w;
int i;
int j;

static uint16_t *main_data;
static float *ptr_data;

void init_vars() {
    factor = 1.5f;
    h = 2048;
    w = 4096;
    stride = w * sizeof(float);
    main_stride = w * sizeof(uint16_t);

    size_t main_size = (size_t)h * w * sizeof(uint16_t);
    size_t ptr_size = (size_t)h * w * sizeof(float);

    main_data = aligned_alloc(64, main_size);
    ptr_data = aligned_alloc(64, ptr_size);

    if (!main_data || !ptr_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < (size_t)h * w; idx++) {
        main_data[idx] = (uint16_t)(idx % 32768);
        ptr_data[idx] = 0.0f;
    }

    main_ptr = main_data;
    ptr = ptr_data;
}