#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64

static size_t total_data_size = DATA_SIZE_MB * 1024ULL * 1024ULL;

int16_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

void init_vars() {
    const int row_size = 16;
    h = (total_data_size / sizeof(uint16_t)) / row_size;
    if (h > 1000000) h = 1000000;
    h -= 5;
    if (h < 1) h = 1;

    srcStride = row_size;
    tmpStride = 16;

    pad = 10;

    size_t src_total_elements = (h + 5) * srcStride;
    size_t tmp_total_elements = (h + 5) * tmpStride;

    src = aligned_alloc(32, src_total_elements * sizeof(uint16_t));
    tmp = aligned_alloc(32, tmp_total_elements * sizeof(int16_t));

    if (!src || !tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_total_elements; i++) {
        src[i] = rand() & 0x3FF;
    }
    for (size_t i = 0; i < tmp_total_elements; i++) {
        tmp[i] = 0;
    }
}