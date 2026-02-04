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
#define ARRAY_ELEMENT_COUNT ((DATA_SIZE_MB * 1024 * 1024) / sizeof(int16_t))

static int16_t *alloc_aligned_array(size_t count) {
    void *ptr;
    if (posix_memalign(&ptr, 32, count * sizeof(int16_t)) != 0) {
        exit(1);
    }
    return (int16_t *)ptr;
}

void init_vars() {
    const size_t total_elements = ARRAY_ELEMENT_COUNT;
    buf = alloc_aligned_array(total_elements);
    ref_buf = alloc_aligned_array(total_elements);
    wptr = alloc_aligned_array(total_elements);

    dpitch = 16;
    pitch = 16;

    for (size_t idx = 0; idx < total_elements; ++idx) {
        buf[idx] = rand() % 65536 - 32768;
        ref_buf[idx] = rand() % 65536 - 32768;
        wptr[idx] = rand() % 65536 - 32768;
    }

    i = 0;
    j = 0;
}