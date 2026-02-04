#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dststride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

static uint8_t *dst_buffer;
static uint8_t *tmp_buffer;
static uint8_t filter_data[5] = {0, 10, 20, 15, 5};
static uint8_t cm_data[256];

void init_vars() {
    h = 4096;
    dststride = 64;

    for (int i = 0; i < 256; ++i) {
        cm_data[i] = (uint8_t)(i & 0xFF);
    }

    dst_buffer = aligned_alloc(32, h * dststride);
    tmp_buffer = aligned_alloc(32, (h + 2) * 4 * sizeof(uint8_t));

    dst = dst_buffer;
    tmp = tmp_buffer + 4;
    cm = cm_data;
    filter = filter_data;

    for (int i = 0; i < (h + 2) * 4; ++i) {
        tmp_buffer[i] = rand() & 0xFF;
    }
}