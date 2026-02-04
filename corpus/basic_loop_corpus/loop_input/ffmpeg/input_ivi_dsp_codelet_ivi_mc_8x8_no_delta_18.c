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

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB total data

static int16_t *buf_storage;
static int16_t *ref_buf_storage;

void init_vars() {
    const int block_height = 8;
    const int block_width = 8;

    ptrdiff_t effective_pitch = 16; // Ensure alignment and avoid overlap
    dpitch = effective_pitch;
    pitch = effective_pitch;

    size_t total_elements = (DATA_SIZE / sizeof(int16_t));
    buf_storage = (int16_t*)aligned_alloc(32, total_elements * sizeof(int16_t));
    ref_buf_storage = (int16_t*)aligned_alloc(32, total_elements * sizeof(int16_t));

    if (!buf_storage || !ref_buf_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        ref_buf_storage[idx] = rand() % 65536 - 32768;
    }

    buf = buf_storage;
    ref_buf = ref_buf_storage;

    i = 0;
    j = 0;
}