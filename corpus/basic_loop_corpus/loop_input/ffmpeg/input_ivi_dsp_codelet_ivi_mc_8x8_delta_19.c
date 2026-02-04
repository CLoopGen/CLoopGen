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

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data to target ~0.01s runtime

static int16_t *buf_data;
static int16_t *ref_buf_data;
static int16_t *wptr_data;

void init_vars() {
    buf_data = aligned_alloc(32, DATA_SIZE);
    ref_buf_data = aligned_alloc(32, DATA_SIZE);
    wptr_data = aligned_alloc(32, DATA_SIZE);

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(int16_t); idx++) {
        buf_data[idx] = rand() % 1024;
        ref_buf_data[idx] = rand() % 1024;
        wptr_data[idx] = rand() % 1024;
    }

    dpitch = 8;
    pitch = 8;

    buf = buf_data;
    ref_buf = ref_buf_data;
    wptr = wptr_data;
    i = 0;
    j = 0;
}