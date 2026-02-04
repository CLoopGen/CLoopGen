#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

FFTSample *dest;
int w;
int w2;
int i;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB of data (~0.01 sec on modern CPU)
    dest = (FFTSample*)aligned_alloc(32, data_size * sizeof(FFTSample));
    
    for (size_t idx = 0; idx < data_size; idx++) {
        dest[idx] = (FFTSample)(idx % 1000);
    }

    w = 1000000;
    w2 = w + 2000000;

    i = 0;
}

__attribute__((destructor))
static void cleanup() {
    if (dest) {
        free(dest);
    }
}