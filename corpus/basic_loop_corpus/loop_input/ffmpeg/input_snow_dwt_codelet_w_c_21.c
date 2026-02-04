#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *pix1;
uint8_t *pix2;
ptrdiff_t line_size;
int w;
int h;
int i;
int j;
int tmp[1024];

void init_vars() {
    w = 32;
    h = 32;
    line_size = w;

    uint8_t *mem1 = aligned_alloc(32, w * h);
    uint8_t *mem2 = aligned_alloc(32, w * h);

    pix1 = mem1;
    pix2 = mem2;

    for (int idx = 0; idx < w * h; idx++) {
        mem1[idx] = rand() % 256;
        mem2[idx] = rand() % 256;
    }

    for (int idx = 0; idx < 1024; idx++) {
        tmp[idx] = 0;
    }

    i = 0;
    j = 0;
}