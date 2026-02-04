#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

FFTSample *data;
int n;
int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~256 MB of data to ensure sufficient runtime
    data = (FFTSample*)aligned_alloc(32, data_size * sizeof(FFTSample));
    if (!data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data[idx] = (FFTSample)(idx % 1000) / 100.0f;
    }

    n = (int)(data_size - 1); // Ensure i+2 is within bounds: i < n-2 => max i = n-3, so i+2 = n-1
}