#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
ptrdiff_t pitch;
int i;
int32_t *src;
int t0;
int t1;
int t2;
int t3;
int t4;

static int32_t *src_data;
static int16_t *out_data;
static size_t total_elements = (1 << 20); // ~4MB input, ~1M int32_t elements

void init_vars() {
    size_t num_rows = total_elements / 4;
    size_t out_size = num_rows * 4;

    src_data = aligned_alloc(32, total_elements * sizeof(int32_t));
    out_data = aligned_alloc(32, out_size * sizeof(int16_t));
    pitch = 4;

    if (!src_data || !out_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_elements; ++i) {
        src_data[i] = rand() % 5 - 2;
    }
    for (size_t i = 0; i < out_size; ++i) {
        out_data[i] = 0;
    }

    src = src_data;
    out = out_data;
}