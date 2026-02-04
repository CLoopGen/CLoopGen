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

static uint8_t *src_buf;
static uint8_t *tmp_buf;
static uint8_t filter_buf[5] = {0, 2, 4, 2, 1}; 
static uint8_t cm_buf[512];

void init_vars() {
    h = 1 << 14; 
    srcstride = 16;
    size_t src_size = (h + 4) * srcstride;
    src_buf = aligned_alloc(32, src_size);
    tmp_buf = aligned_alloc(32, (h + 4) * 8);
    src = src_buf + srcstride; 
    tmp = tmp_buf;
    filter = filter_buf;
    cm = cm_buf + 256; 

    for (size_t i = 0; i < src_size; i++) {
        src_buf[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < 512; i++) {
        cm_buf[i] = i & 0xFF;
    }
}