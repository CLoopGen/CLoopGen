#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t mlinesize;
ptrdiff_t alinesize;
ptrdiff_t dlinesize;
int w;
int h;
int half;
int max;

uint16_t *msrc;
uint16_t *asrc;
uint16_t *dst;

int x;
int y;

void init_vars() {
    w = 2048;
    h = 256;
    half = 512;
    max = 1024;

    mlinesize = w * sizeof(uint16_t);
    alinesize = w * sizeof(uint16_t);
    dlinesize = w * sizeof(uint16_t);

    size_t total_size = (size_t)w * h * sizeof(uint16_t);

    msrc = aligned_alloc(32, total_size);
    asrc = aligned_alloc(32, total_size);
    dst = aligned_alloc(32, total_size);

    for (int i = 0; i < w * h; i++) {
        msrc[i] = rand() % max;
        asrc[i] = rand() % (max + 1);
    }
}