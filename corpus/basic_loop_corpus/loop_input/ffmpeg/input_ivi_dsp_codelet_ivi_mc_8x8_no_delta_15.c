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

static int16_t *buf_data;
static int16_t *ref_buf_data;
static int16_t *wptr_data;
static size_t total_size = 1 << 20; // 1MB of int16_t data (~512k elements)

void init_vars() {
    buf_data = aligned_alloc(32, total_size * sizeof(int16_t));
    ref_buf_data = aligned_alloc(32, total_size * sizeof(int16_t));
    wptr_data = aligned_alloc(32, total_size * sizeof(int16_t));

    if (!buf_data || !ref_buf_data || !wptr_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        buf_data[idx] = rand() % 65536 - 32768;
        ref_buf_data[idx] = rand() % 65536 - 32768;
        wptr_data[idx] = rand() % 65536 - 32768;
    }

    buf = buf_data;
    dpitch = 128;
    ref_buf = ref_buf_data;
    pitch = 128;
    wptr = wptr_data;
}