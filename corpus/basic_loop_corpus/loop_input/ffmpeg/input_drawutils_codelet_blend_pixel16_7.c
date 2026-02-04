#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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

static uint8_t *mask_data = NULL;

void init_vars() {
    l2depth = 3;
    xmshf = 3;
    xmmod = 7;
    mbits = 0xFF;
    mmult = 1;
    w = 4096;
    h = 4096;
    xm0 = 0;
    mask_linesize = (w + 7) / 8; 

    size_t total_mask_size = (size_t)mask_linesize * h;

    mask_data = (uint8_t*)aligned_alloc(32, total_mask_size);
    if (!mask_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(mask_data, 0x5A, total_mask_size);

    mask = mask_data;
    t = 0;
    xm = 0;
    x = 0;
    y = 0;
}