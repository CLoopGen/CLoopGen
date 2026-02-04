#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int8_t *filter = filter_data;

uint16_t *src_base;
uint16_t *src;
ptrdiff_t srcstride = 1024;

int16_t *tmp_base;
int16_t *tmp;

void init_vars() {
    src_base = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * (height + 7) * srcstride);
    tmp_base = (int16_t*)aligned_alloc(64, sizeof(int16_t) * 64 * (height + 7));
    
    if (!src_base || !tmp_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < (height + 7) * srcstride; i++) {
        src_base[i] = rand() & 0xFFFF;
    }

    for (int i = 0; i < 64 * (height + 7); i++) {
        tmp_base[i] = 0;
    }

    src = src_base + 3 * srcstride; // Offset to allow x - 3 access without underflow
    tmp = tmp_base;
}