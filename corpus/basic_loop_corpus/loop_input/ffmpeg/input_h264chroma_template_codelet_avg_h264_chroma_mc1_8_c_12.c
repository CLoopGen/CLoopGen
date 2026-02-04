#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int B;
int C;
int D;
int i;

void init_vars() {
    A = 16; B = 32; C = 15; D = 8;
    h = 4096;
    stride = 4096;

    src = aligned_alloc(32, (size_t)(stride) * (h + 1));
    dst = aligned_alloc(32, (size_t)(stride) * h);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < stride; x++) {
            src[y * stride + x] = rand() & 0xFF;
            dst[y * stride + x] = rand() & 0xFF;
        }
    }

    i = 0;
}