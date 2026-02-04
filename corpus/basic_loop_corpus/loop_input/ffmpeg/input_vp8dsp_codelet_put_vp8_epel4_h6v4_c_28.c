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

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

static uint8_t *src_buffer;
static uint8_t *tmp_buffer;
static uint8_t filter_buffer[6] = {8, 12, 16, 20, 24, 32};
static uint8_t cm_buffer[512];

void init_vars() {
    h = 1024;
    srcstride = 2048;

    src_buffer = aligned_alloc(32, TOTAL_ELEMENTS * sizeof(uint8_t));
    tmp_buffer = aligned_alloc(32, (h + 4 - 1) * 4 * sizeof(uint8_t));
    src = src_buffer;
    tmp = tmp_buffer;
    filter = filter_buffer;
    cm = cm_buffer;

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 512; i++) {
        cm_buffer[i] = i - 256 < 0 ? 0 : (i - 256 > 255 ? 255 : i - 256);
    }
}