#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t FFTSample;

int m;
FFTSample *tab;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data to target ~0.01s runtime
    m = data_size / sizeof(FFTSample);   // number of elements

    // Ensure m is divisible by 4 and at least 8 to satisfy loop condition i < m/4 and access m/2 - i safely
    m = (m / 4) * 4;
    if (m < 8) m = 8;

    tab = (FFTSample*)aligned_alloc(32, m * sizeof(FFTSample));
    if (!tab) exit(1);

    // Initialize array with dummy data
    for (int i = 0; i < m; i++) {
        tab[i] = (FFTSample)(i * 31);
    }
}