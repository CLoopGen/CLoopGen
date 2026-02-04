#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int16_t FFTSample;

int i;
int m;
FFTSample *tab;

void init_vars() {
    m = 1 << 20;  // 1M elements, yields ~256KB of data (each element is 2 bytes)
    tab = (FFTSample*)aligned_alloc(32, m * sizeof(FFTSample));
    if (!tab) {
        exit(1);
    }
    for (int idx = 0; idx < m; idx++) {
        tab[idx] = (FFTSample)(idx & 0xFFFF);
    }
}

void loop();