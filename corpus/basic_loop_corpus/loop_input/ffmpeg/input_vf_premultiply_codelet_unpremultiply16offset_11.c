#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t mlinesize;
ptrdiff_t alinesize;
ptrdiff_t dlinesize;
int w;
int h;
int max;
int offset;
uint16_t *msrc;
uint16_t *asrc;
uint16_t *dst;
int x;
int y;

static uint16_t *msrc_data;
static uint16_t *asrc_data;
static uint16_t *dst_data;

void init_vars() {
    w = 2048;
    h = 128;
    max = 1023;
    offset = 128;
    mlinesize = w * sizeof(uint16_t);
    alinesize = w * sizeof(uint16_t);
    dlinesize = w * sizeof(uint16_t);

    size_t total_size = (size_t)w * h * sizeof(uint16_t);

    msrc_data = aligned_alloc(32, total_size);
    asrc_data = aligned_alloc(32, total_size);
    dst_data = aligned_alloc(32, total_size);

    if (!msrc_data || !asrc_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < w * h; i++) {
        msrc_data[i] = rand() % 1500;
        asrc_data[i] = rand() % 1200;
    }

    msrc = msrc_data;
    asrc = asrc_data;
    dst = dst_data;
}