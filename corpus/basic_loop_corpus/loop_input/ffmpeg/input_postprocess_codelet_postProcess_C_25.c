#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int black;
uint64_t *yHistogram;
uint64_t maxClipped;
uint64_t clipped;

void init_vars() {
    size_t histogram_size = 256;
    yHistogram = (uint64_t*)calloc(histogram_size, sizeof(uint64_t));
    if (!yHistogram) {
        exit(1);
    }

    for (size_t i = 0; i < histogram_size; i++) {
        yHistogram[i] = 1000000ULL;
    }

    maxClipped = 128000000ULL;
    clipped = 256000000ULL;
    black = 255;
}