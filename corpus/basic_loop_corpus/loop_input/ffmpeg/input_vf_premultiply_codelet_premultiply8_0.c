#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *msrc;
uint8_t *asrc;
uint8_t *dst;
ptrdiff_t mlinesize;
ptrdiff_t alinesize;
ptrdiff_t dlinesize;
int w;
int h;
int x;
int y;

static uint8_t *msrc_data;
static uint8_t *asrc_data;
static uint8_t *dst_data;

void init_vars() {
    w = 2048;
    h = 128;

    mlinesize = w;
    alinesize = w;
    dlinesize = w;

    size_t msize = (size_t)mlinesize * h;
    size_t asize = (size_t)alinesize * h;
    size_t dsize = (size_t)dlinesize * h;

    msrc_data = aligned_alloc(32, msize);
    asrc_data = aligned_alloc(32, asize);
    dst_data = aligned_alloc(32, dsize);

    msrc = msrc_data;
    asrc = asrc_data;
    dst = dst_data;

    for (size_t i = 0; i < msize; i++) {
        msrc_data[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < asize; i++) {
        asrc_data[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dsize; i++) {
        dst_data[i] = 0;
    }
}