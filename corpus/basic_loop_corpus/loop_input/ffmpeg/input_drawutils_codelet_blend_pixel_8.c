#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *mask;
int mask_linesize;
int l2depth;
unsigned int w;
unsigned int h;
unsigned int xm0;
unsigned int xm;
unsigned int x;
unsigned int y;
unsigned int t;
unsigned int xmshf;
unsigned int xmmod;
unsigned int mbits;
unsigned int mmult;

static uint8_t *mask_buffer;
static size_t total_mask_size;

void init_vars() {
    l2depth = 3;
    xmshf = 3;
    xmmod = 7;
    mbits = 0xFF;
    mmult = 1;
    w = 4096;
    h = 4096;
    xm0 = 0;
    xm = 0;
    x = 0;
    y = 0;
    t = 0;
    mask_linesize = 4096;

    total_mask_size = ((h * mask_linesize) + (1 << xmshf)) * sizeof(uint8_t);
    mask_buffer = (uint8_t*)aligned_alloc(32, total_mask_size);
    if (!mask_buffer) {
        exit(1);
    }
    for (size_t i = 0; i < total_mask_size; i++) {
        mask_buffer[i] = rand() & 0xFF;
    }
    mask = mask_buffer;
}