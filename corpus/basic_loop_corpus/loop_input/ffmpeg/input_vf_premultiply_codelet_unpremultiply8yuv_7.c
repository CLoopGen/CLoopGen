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

int w = 1024;
int h = 512;
int x;
int y;

static uint8_t *msrc_data;
static uint8_t *asrc_data;
static uint8_t *dst_data;

void init_vars() {
    const size_t total_size = (size_t)w * h;
    msrc_data = aligned_alloc(32, total_size);
    asrc_data = aligned_alloc(32, total_size);
    dst_data = aligned_alloc(32, total_size);

    for (size_t i = 0; i < total_size; i++) {
        msrc_data[i] = rand() % 256;
        asrc_data[i] = rand() % 257;
        dst_data[i] = 0;
    }

    msrc = msrc_data;
    asrc = asrc_data;
    dst = dst_data;

    mlinesize = w;
    alinesize = w;
    dlinesize = w;
}