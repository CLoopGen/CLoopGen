#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *buf;
ptrdiff_t dpitch;
int16_t *ref_buf;
ptrdiff_t pitch;
int i;
int j;

static int16_t *buf_data;
static int16_t *ref_buf_data;
static size_t total_size = 1 << 20; // 1MB of data

void init_vars() {
    buf_data = aligned_alloc(32, total_size);
    ref_buf_data = aligned_alloc(32, total_size);

    size_t num_elements = total_size / sizeof(int16_t);
    for (size_t idx = 0; idx < num_elements; idx++) {
        buf_data[idx] = rand() % 100;
        ref_buf_data[idx] = rand() % 100;
    }

    dpitch = 8;
    pitch = 8;

    buf = buf_data;
    ref_buf = ref_buf_data;
}