#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

int i;
int m;
FFTSample *tab;

void init_vars() {
    m = 67108864; // 64M elements -> ~256MB for float array
    tab = (FFTSample*)aligned_alloc(32, m * sizeof(FFTSample));
    if (!tab) exit(1);

    for (int idx = 0; idx < m; idx++) {
        tab[idx] = (FFTSample)(idx % 1000);
    }
}