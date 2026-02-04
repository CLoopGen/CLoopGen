#include <stdint.h>
#include <stdlib.h>

int white;
uint64_t * yHistogram;
uint64_t maxClipped;
uint64_t clipped;

void init_vars() {
    yHistogram = (uint64_t*)aligned_alloc(64, 256 * sizeof(uint64_t));
    for (int i = 0; i < 256; i++) {
        yHistogram[i] = 1000000ULL;
    }
    maxClipped = 256000000ULL;
    clipped = maxClipped;
}