#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
uint16_t *dst;
uint16_t *src;
int init_x = 0;
int width;
int save_upper_left = 0;
int save_upper_right = 0;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB of data
    size_t num_elements = data_size / sizeof(uint16_t);

    width = (int)num_elements;

    src = (uint16_t *)aligned_alloc(32, data_size);
    dst = (uint16_t *)aligned_alloc(32, data_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
    }
}