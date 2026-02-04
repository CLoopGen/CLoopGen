#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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
static uint8_t filter_data[5];
static uint8_t cm_data[256];

void init_vars() {
    h = 1000000 / 4;  // Approximate to get ~1M operations (each inner loop does 4 writes)

    srcstride = 8;  // Ensure stride is at least as big as needed for src access

    size_t src_size = (h + 3) * srcstride;  // Account for h+4-1 iterations and offset indexing
    src_buffer = calloc(src_size, sizeof(uint8_t));
    if (!src_buffer) exit(1);

    tmp_buffer = calloc(h * 4, sizeof(uint8_t));  // Total tmp storage: h rows * 4 elements
    if (!tmp_buffer) exit(1);

    src = src_buffer + srcstride;  // Start src with offset so x-1 is valid in first iteration
    tmp = tmp_buffer;

    // Initialize filter with safe values: symmetric around center
    filter_data[0] = 0;
    filter_data[1] = 8;
    filter_data[2] = 64;
    filter_data[3] = 8;
    filter_data[4] = 1;
    filter = filter_data;

    // Initialize cm as identity mapping with clipping
    for (int i = 0; i < 256; i++) {
        cm_data[i] = (uint8_t)i;
    }
    cm = cm_data;

    x = 0;
    y = 0;
}