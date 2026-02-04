#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *msrc;
uint8_t *asrc;
uint8_t *dst;
ptrdiff_t mlinesize;
ptrdiff_t alinesize;
ptrdiff_t dlinesize;
int w;
int h;
int offset;
int x;
int y;

static uint8_t *msrc_data;
static uint8_t *asrc_data;
static uint8_t *dst_data;

void init_vars() {
    w = 2048;
    h = 128;
    offset = 10;

    msrc_data = (uint8_t*)aligned_alloc(32, w * h * sizeof(uint8_t));
    asrc_data = (uint8_t*)aligned_alloc(32, w * h * sizeof(uint8_t));
    dst_data = (uint8_t*)aligned_alloc(32, w * h * sizeof(uint8_t));

    if (!msrc_data || !asrc_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < w * h; i++) {
        msrc_data[i] = rand() % 256;
        asrc_data[i] = rand() % 257; 
        dst_data[i] = 0;
    }

    mlinesize = w;
    alinesize = w;
    dlinesize = w;

    msrc = msrc_data;
    asrc = asrc_data;
    dst = dst_data;
}