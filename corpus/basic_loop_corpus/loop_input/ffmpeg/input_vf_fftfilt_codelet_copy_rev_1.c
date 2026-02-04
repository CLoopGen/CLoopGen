#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float FFTSample;

FFTSample *dest;
int w2;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime
    dest = (FFTSample*)aligned_alloc(32, data_size);
    if (!dest) exit(1);

    w2 = data_size / sizeof(FFTSample) - 1; // Ensure w2 is valid index bound
    i = 0;

    for (size_t idx = 0; idx < data_size / sizeof(FFTSample); ++idx) {
        dest[idx] = (FFTSample)(idx % 1000);
    }
}