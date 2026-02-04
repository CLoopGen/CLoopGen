#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src1;
ptrdiff_t srcStride;
int16_t *tmp;
int h;
int i;

static uint8_t *src1_data;
static int16_t *tmp_data;

void init_vars() {
    const size_t total_data_size = 128 * 1024 * 1024;
    const size_t base_pitch = 1024;
    h = (total_data_size / base_pitch) - 10;
    if (h <= 0) h = 1000;

    srcStride = base_pitch;

    src1_data = aligned_alloc(32, (h + 10) * srcStride * sizeof(uint8_t));
    tmp_data = aligned_alloc(32, (h + 5) * 8 * sizeof(int16_t));

    if (!src1_data || !tmp_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < (h + 10) * srcStride; idx++) {
        src1_data[idx] = rand() % 256;
    }
    for (size_t idx = 0; idx < (h + 5) * 8; idx++) {
        tmp_data[idx] = 0;
    }

    src1 = src1_data - 2;
    tmp = tmp_data;
}