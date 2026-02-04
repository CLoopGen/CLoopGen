#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)
#define TMP_OFFSET 12
#define TMP_EXTRA (TMP_OFFSET + 11) // -2 to +10 inclusive, times 8 stride -> 13 elements needed
#define DST_HEIGHT 8

void init_vars() {
    const size_t tmp_total = TOTAL_ELEMENTS + TMP_EXTRA * 8;
    tmp = aligned_alloc(32, tmp_total * sizeof(int16_t));
    
    dstStride = 1;
    w = TOTAL_ELEMENTS;

    dst = aligned_alloc(32, w * DST_HEIGHT * sizeof(uint8_t));

    cm = malloc(1024 * sizeof(uint8_t));
    
    if (!tmp || !dst || !cm) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < tmp_total; idx++) {
        tmp[idx] = rand() % 256 - 128;
    }

    for (int idx = 0; idx < 1024; idx++) {
        cm[idx] = rand() % 256;
    }
}