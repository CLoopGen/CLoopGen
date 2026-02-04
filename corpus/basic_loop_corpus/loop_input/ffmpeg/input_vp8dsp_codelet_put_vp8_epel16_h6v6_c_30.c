#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

static uint8_t *src_storage;
static uint8_t *tmp_storage;
static uint8_t filter_storage[6];
static uint8_t cm_storage[512];

void init_vars() {
    h = 1024;
    srcstride = 16 + 8; // Ensure horizontal padding for safe access: x-2 to x+3 => need +5, pad more for alignment

    size_t src_size = (h + 6 - 1 + 1) * srcstride; // Extra rows and stride
    src_storage = aligned_alloc(32, src_size);
    src = src_storage;

    size_t tmp_size = (h + 6 - 1) * 16;
    tmp_storage = aligned_alloc(32, tmp_size);
    tmp = tmp_storage;

    filter = filter_storage;
    cm = cm_storage;

    // Initialize filter with example values (e.g., symmetric)
    filter[0] = 10;
    filter[1] = 20;
    filter[2] = 30;
    filter[3] = 30;
    filter[4] = 20;
    filter[5] = 10;

    // Initialize cm as identity mapping with clipping: cm[i] = clamp(i, 0, 255)
    for (int i = 0; i < 512; i++) {
        cm[i] = (i < 0) ? 0 : (i > 255) ? 255 : (uint8_t)i;
    }

    // Initialize source data to prevent out-of-bounds computation issues
    memset(src_storage, 128, src_size);

    // Initialize tmp to avoid undefined behavior
    memset(tmp_storage, 0, tmp_size);

    // Set initial loop variables
    x = 0;
    y = 0;
}