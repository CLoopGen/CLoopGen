#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

static uint8_t *src_data;
static uint8_t *tmp_data;
static uint8_t filter_data[6] = {1, 2, 3, 4, 5, 6};
static uint8_t cm_data[256] = {0};

void init_vars() {
    h = 4096;
    srcstride = 8 + 4; // ensures access up to x+3 and down to x-2 without going out of bounds

    size_t src_size = (h + 6 - 1) * srcstride;
    src_data = aligned_alloc(32, src_size);
    tmp_data = aligned_alloc(32, h * 8);

    if (!src_data || !tmp_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_data[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 256; i++) {
        cm_data[i] = i & 0xFF;
    }

    src = src_data;
    tmp = tmp_data;
    filter = filter_data;
    cm = cm_data;
}