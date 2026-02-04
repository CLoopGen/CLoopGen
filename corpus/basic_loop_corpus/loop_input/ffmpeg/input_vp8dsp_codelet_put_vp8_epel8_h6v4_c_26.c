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

static uint8_t *src_buffer;
static uint8_t *tmp_buffer;
static uint8_t filter_data[6] = {8, 12, 16, 14, 7, 3};
static uint8_t cm_data[512];

void init_vars() {
    h = 2048;
    srcstride = 32;
    
    size_t src_size = (h + 4) * srcstride;
    src_buffer = aligned_alloc(32, src_size);
    memset(src_buffer, 0x5A, src_size);
    src = src_buffer;

    tmp_buffer = aligned_alloc(32, h * 8);
    memset(tmp_buffer, 0, h * 8);
    tmp = tmp_buffer;

    filter = filter_data;

    for (int i = 0; i < 512; i++) {
        cm_data[i] = (uint8_t)((i < 256) ? 0 : (i >= 512-256) ? 255 : i - 256);
    }
    cm = cm_data;

    x = 0;
    y = 0;
}