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
int16_t *wptr;

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024 / sizeof(int16_t))

static int16_t *buf_storage;
static int16_t *ref_buf_storage;
static int16_t *wptr_storage;

void init_vars() {
    size_t total_elements = ARRAY_SIZE;
    buf_storage = aligned_alloc(32, total_elements * sizeof(int16_t));
    ref_buf_storage = aligned_alloc(32, total_elements * sizeof(int16_t));
    wptr_storage = aligned_alloc(32, total_elements * sizeof(int16_t));

    for (size_t idx = 0; idx < total_elements; idx++) {
        buf_storage[idx] = rand() % 1000;
        ref_buf_storage[idx] = rand() % 1000;
        wptr_storage[idx] = rand() % 1000;
    }

    buf = buf_storage;
    dpitch = 16;
    ref_buf = ref_buf_storage;
    pitch = 16;
    wptr = wptr_storage;
}