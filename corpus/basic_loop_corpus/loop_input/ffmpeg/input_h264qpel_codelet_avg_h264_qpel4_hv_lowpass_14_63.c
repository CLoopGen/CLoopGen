#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(uint16_t))
#define ROWS (1000)
#define COLS (TOTAL_ELEMENTS / ROWS)

void init_vars() {
    pad = 10;

    srcStride = COLS;
    tmpStride = COLS;

    h = ROWS - 5;

    src = aligned_alloc(32, TOTAL_ELEMENTS * sizeof(uint16_t));
    int32_t *tmp_base = aligned_alloc(32, TOTAL_ELEMENTS * sizeof(int32_t));

    if (!src || !tmp_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        src[idx] = (uint16_t)(idx % 1024);
    }

    tmp = tmp_base;
}