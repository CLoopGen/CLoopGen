#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double FFTSample;

int m;
FFTSample *tab;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB of data
    m = (int)(data_size / sizeof(FFTSample));
    // Ensure m is divisible by 4 and at least 4 to satisfy loop condition i < m/4
    m = (m / 4) * 4;
    if (m < 4) m = 4;

    tab = (FFTSample*)aligned_alloc(32, data_size);
    if (!tab) exit(1);

    for (int i = 0; i < m; i++) {
        tab[i] = (FFTSample)(i * 2.5);
    }
}