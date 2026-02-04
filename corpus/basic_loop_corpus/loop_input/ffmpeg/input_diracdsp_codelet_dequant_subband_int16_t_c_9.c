#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;
int qf;
int qs;
int tot_v;
int tot_h;
int i;
int y;

void init_vars() {
    qf = 17;
    qs = 8;
    tot_h = 4096;
    tot_v = 4096;
    stride = tot_h * sizeof(int16_t);

    size_t src_size = (size_t)tot_v * tot_h * sizeof(int16_t);
    size_t dst_size = (size_t)tot_v * stride;

    src = (uint8_t *)aligned_alloc(32, src_size);
    dst = (uint8_t *)aligned_alloc(32, dst_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    int16_t *src_data = (int16_t *)src;
    for (size_t idx = 0; idx < src_size / sizeof(int16_t); idx++) {
        src_data[idx] = (int16_t)(rand() % 2047 - 1024);
    }

    for (size_t idx = 0; idx < dst_size / sizeof(int16_t); idx++) {
        ((int16_t *)dst)[idx] = 0;
    }
}