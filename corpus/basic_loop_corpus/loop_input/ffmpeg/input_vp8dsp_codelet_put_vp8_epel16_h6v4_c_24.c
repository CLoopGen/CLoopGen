#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define TOTAL_ITERATIONS 1000000

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
static uint8_t filter_buffer[6] = {8, 12, 24, 20, 9, 4};
static uint8_t cm_buffer[512];

void init_vars() {
    h = 1000;
    srcstride = 32;

    size_t src_size = (h + 4 - 1) * srcstride;
    src_buffer = aligned_alloc(32, src_size);
    tmp_buffer = aligned_alloc(32, 16 * (h + 4 - 1));
    src = src_buffer;
    tmp = tmp_buffer;

    filter = filter_buffer;

    for (int i = 0; i < 512; i++) {
        cm_buffer[i] = (uint8_t)(i & 0xFF);
    }
    cm = cm_buffer;

    memset(src_buffer, 128, src_size);
}