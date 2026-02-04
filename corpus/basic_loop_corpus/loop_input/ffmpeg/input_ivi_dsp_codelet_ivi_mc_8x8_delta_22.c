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

static int16_t *buf_storage;
static int16_t *ref_buf_storage;

void init_vars() {
    const int size = 8;
    const int total_size = 1 << 20; // ~1MB of data (adjustable)

    buf_storage = aligned_alloc(32, sizeof(int16_t) * total_size);
    ref_buf_storage = aligned_alloc(32, sizeof(int16_t) * total_size);

    for (int idx = 0; idx < total_size; idx++) {
        buf_storage[idx] = rand() % 100;
        ref_buf_storage[idx] = rand() % 100;
    }

    buf = buf_storage;
    ref_buf = ref_buf_storage;

    dpitch = size + 4;
    pitch = size + 4;

    i = 0;
    j = 0;
}