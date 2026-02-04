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

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of int16_t data

static int16_t *buf_storage;
static int16_t *ref_buf_storage;

void init_vars() {
    buf_storage = aligned_alloc(32, DATA_SIZE);
    ref_buf_storage = aligned_alloc(32, DATA_SIZE);

    if (!buf_storage || !ref_buf_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(int16_t); idx++) {
        buf_storage[idx] = rand() % 1000;
        ref_buf_storage[idx] = rand() % 1000;
    }

    buf = buf_storage;
    ref_buf = ref_buf_storage;
    dpitch = 4;
    pitch = 4;
}