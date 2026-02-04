#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;
int qf;
int qs;
int tot_v;
int tot_h;
int i;
int y;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime estimate
    const size_t elem_size = sizeof(int32_t);
    tot_h = (total_data_size / elem_size) / 16;
    tot_v = 16;
    
    if (tot_h == 0) tot_h = 1;
    size_t src_size = tot_h * tot_v * elem_size;
    size_t dst_size = tot_v * (tot_h * elem_size);

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src_buffer, 0, src_size);
    memset(dst_buffer, 0, dst_size);

    for (size_t idx = 0; idx < src_size / elem_size; idx++) {
        int32_t val = (rand() % 7) - 3;
        ((int32_t*)src_buffer)[idx] = val;
    }

    src = src_buffer;
    dst = dst_buffer;
    stride = tot_h * elem_size;
    qf = 17;
    qs = 8;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}