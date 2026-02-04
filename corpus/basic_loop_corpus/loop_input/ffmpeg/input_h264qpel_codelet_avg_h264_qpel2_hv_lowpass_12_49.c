#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * (1 << 20)) / sizeof(uint16_t))

static int32_t *tmp_buffer;
static uint16_t *src_buffer;

int32_t *tmp;
uint16_t *src;
int tmpStride = 1;
int srcStride = 1;
int h = (TOTAL_ELEMENTS / 8) - 5; // ensures i < h + 5 stays in bounds
int pad = 10;
int i;

void init_vars() {
    size_t total_tmp_needed = (h + 5) * tmpStride;
    size_t total_src_needed = (h + 5) * srcStride + 3; // accounts for src[-2] to src[4] => needs +3 on each side

    tmp_buffer = aligned_alloc(32, total_tmp_needed * sizeof(int32_t));
    src_buffer = aligned_alloc(32, (total_src_needed + 4) * sizeof(uint16_t)); // extra padding at start and end

    if (!tmp_buffer || !src_buffer) {
        exit(1);
    }

    src = src_buffer + 2; // shift so that src[-2] is valid
    tmp = tmp_buffer;

    for (size_t idx = 0; idx < total_src_needed + 4; ++idx) {
        src_buffer[idx] = (uint16_t)(idx % 257);
    }
}