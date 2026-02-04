#include <stdint.h>
#include <stdlib.h>

int black;
uint64_t *yHistogram;
uint64_t maxClipped;
uint64_t clipped;

void init_vars() {
    yHistogram = (uint64_t*)aligned_alloc(64, 256 * sizeof(uint64_t));
    for (int i = 0; i < 256; i++) {
        yHistogram[i] = 100000ULL;
    }
    maxClipped = 25500000ULL;
    clipped = maxClipped + 100000ULL;
    black = 255;
}