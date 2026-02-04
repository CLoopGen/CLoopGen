#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w2;
int x;
int32_t *b;
int32_t *tmp;

static int32_t *b_data;
static int32_t *tmp_data;

void init_vars() {
    const size_t total_size = 128 * 1024 * 1024; // 128 MB of input data
    const size_t tmp_elements = total_size / (sizeof(int32_t) * 2);
    const size_t b_elements = tmp_elements * 2 + w2;

    w2 = (int)tmp_elements;

    tmp_data = (int32_t*)aligned_alloc(32, tmp_elements * sizeof(int32_t));
    b_data = (int32_t*)aligned_alloc(32, b_elements * sizeof(int32_t));

    if (!tmp_data || !b_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < tmp_elements; i++) {
        tmp_data[i] = (int32_t)(i % 1000);
    }
    for (size_t i = 0; i < b_elements; i++) {
        b_data[i] = (int32_t)((i + 1) % 1000);
    }

    b = b_data;
    tmp = tmp_data;
}