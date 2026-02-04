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
int half;
int shift;
int offset;
uint16_t *msrc;
uint16_t *asrc;
uint16_t *dst;
int x;
int y;

void init_vars() {
    w = 2048;
    h = 128;
    half = 1 << 7;
    shift = 8;
    offset = 128;
    mlinesize = w * sizeof(uint16_t);
    alinesize = w * sizeof(uint16_t);
    dlinesize = w * sizeof(uint16_t);

    size_t total_msize = h * mlinesize;
    size_t total_asize = h * alinesize;
    size_t total_dsize = h * dlinesize;

    msrc = (uint16_t*)aligned_alloc(32, total_msize);
    asrc = (uint16_t*)aligned_alloc(32, total_asize);
    dst  = (uint16_t*)aligned_alloc(32, total_dsize);

    if (!msrc || !asrc || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            msrc[i * (mlinesize / 2) + j] = rand() % 256 + offset;
            asrc[i * (alinesize / 2) + j] = rand() % 256;
        }
    }

    memset(dst, 0, total_dsize);
}