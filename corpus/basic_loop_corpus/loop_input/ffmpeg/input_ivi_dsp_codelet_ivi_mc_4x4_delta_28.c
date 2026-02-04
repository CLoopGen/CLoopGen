#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to ensure sufficient runtime (~0.01s)

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
    // Allocate large buffers to achieve desired execution time
    buf_data = (int16_t*)aligned_alloc(32, DATA_SIZE);
    ref_buf_data = (int16_t*)aligned_alloc(32, DATA_SIZE);
    wptr_data = (int16_t*)aligned_alloc(32, DATA_SIZE);

    if (!buf_data || !ref_buf_data || !wptr_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffer contents to avoid undefined behavior
    for (size_t k = 0; k < DATA_SIZE / sizeof(int16_t); k++) {
        buf_data[k] = rand() % 100;
        ref_buf_data[k] = rand() % 100;
        wptr_data[k] = rand() % 100;
    }

    // Set pitches (row strides in units of int16_t)
    dpitch = 16;  // Must accommodate at least 4 rows with 6 columns each
    pitch = 16;

    // Initialize pointers to start within safe bounds
    buf = buf_data + 8;         // Reserve space for offset indexing
    ref_buf = ref_buf_data + 8;
    wptr = wptr_data + 8;

    // Ensure that during loop: j goes up to 4, and we access j+1 => need 5 elements per row
    // We have 16 pitch and data size >> needed memory, so it's safe
    i = 0;
    j = 0;
}