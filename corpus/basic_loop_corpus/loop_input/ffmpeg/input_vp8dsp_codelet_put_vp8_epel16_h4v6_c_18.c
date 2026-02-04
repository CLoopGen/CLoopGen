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

static uint8_t *src_buffer;
static uint8_t *tmp_buffer;
static uint8_t filter_buffer[5] = {0, 16, 32, 16, 8}; // filter[0] unused in loop, indices 1-4 used
static uint8_t cm_buffer[512]; // centred at 256 to handle input range

void init_vars() {
    h = 10000; // determines height dimension

    srcstride = 32; // larger than width used (16 + 2 for offsets) to prevent overlap

    // Allocate source buffer with padding: we access [x-1], so need at least 1 before and 2 after each row
    size_t src_size = (h + 6 - 1) * srcstride;
    src_buffer = aligned_alloc(32, src_size);
    if (!src_buffer) exit(1);
    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }

    // tmp needs (h+6-1) rows of 16 bytes
    size_t tmp_size = (h + 6 - 1) * 16;
    tmp_buffer = aligned_alloc(32, tmp_size);
    if (!tmp_buffer) exit(1);

    // Initialize cm buffer: map [-256,255] -> [0,511] safely
    for (int i = 0; i < 512; i++) {
        cm_buffer[i] = (uint8_t)(i > 255 ? 255 : (i < 0 ? 0 : i));
    }

    // Assign external pointers
    src = src_buffer;
    tmp = tmp_buffer;
    filter = filter_buffer;
    cm = cm_buffer;

    // Initialize loop counters
    x = 0;
    y = 0;
}