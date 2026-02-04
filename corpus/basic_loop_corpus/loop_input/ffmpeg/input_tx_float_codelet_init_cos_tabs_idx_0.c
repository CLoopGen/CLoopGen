#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

int m;
FFTSample *tab;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient workload
    tab = (FFTSample*)aligned_alloc(32, data_size);
    if (!tab) {
        exit(1);
    }

    m = data_size / sizeof(FFTSample); // m is number of elements

    // Ensure m is divisible by 4 so that m/4 and m/2 are valid indices
    m = (m / 4) * 4;

    // Initialize all elements to avoid undefined behavior
    for (int i = 0; i < m; i++) {
        tab[i] = (FFTSample)(i + 1);
    }
}