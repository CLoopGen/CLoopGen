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

void init_vars() {
    const int block_count = 32768; // Adjust to control total data size
    const int total_size = block_count * 8 * sizeof(int16_t); // ~512KB per buffer

    buf_data = aligned_alloc(32, total_size);
    ref_buf_data = aligned_alloc(32, total_size + 16); // Extra space for +1 access
    wptr_data = aligned_alloc(32, total_size + 16);     // Extra space for +1 access

    if (!buf_data || !ref_buf_data || !wptr_data) {
        exit(1);
    }

    for (int k = 0; k < total_size / sizeof(int16_t); ++k) {
        buf_data[k] = rand() % 1024;
        ref_buf_data[k] = rand() % 1024;
        wptr_data[k] = rand() % 1024;
    }

    // Initialize trailing elements to prevent out-of-bounds reads
    for (int k = total_size / sizeof(int16_t); k < total_size / sizeof(int16_t) + 8; ++k) {
        ref_buf_data[k] = 0;
        wptr_data[k] = 0;
    }

    dpitch = 8;
    pitch = 8;

    buf = buf_data;
    ref_buf = ref_buf_data;
    wptr = wptr_data;
}