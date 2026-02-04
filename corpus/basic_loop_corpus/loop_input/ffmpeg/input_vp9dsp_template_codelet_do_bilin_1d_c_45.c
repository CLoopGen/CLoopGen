#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1 << 24; // Approximately 16.7 million elements for ~0.01 sec runtime
ptrdiff_t ds = 1;
int mxy = 10;
int avg = 1;
uint8_t *dst;
uint8_t *src;
int x;

void init_vars() {
    dst = aligned_alloc(32, sizeof(uint8_t) * (w + abs(ds)));
    src = aligned_alloc(32, sizeof(uint8_t) * (w + abs(ds)));

    for (int i = 0; i < w + abs(ds); i++) {
        dst[i] = rand() % 256;
        src[i] = rand() % 256;
    }
}