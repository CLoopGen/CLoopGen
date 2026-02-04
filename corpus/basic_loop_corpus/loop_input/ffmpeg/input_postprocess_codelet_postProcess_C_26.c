#include <inttypes.h>
#include <stdlib.h>

int white;
uint64_t * yHistogram;
uint64_t maxClipped;
uint64_t clipped;

void init_vars() {
    size_t histogram_size = 256;
    yHistogram = (uint64_t *)malloc(histogram_size * sizeof(uint64_t));
    
    for (size_t i = 0; i < histogram_size; i++) {
        yHistogram[i] = 1000 + i; 
    }

    maxClipped = 100000;
    clipped = 250000;
    white = 0;
}