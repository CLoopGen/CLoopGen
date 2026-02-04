#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

int i;
int m;
FFTSample *tab;

void init_vars() {
    m = 1 << 24; // 16,777,216 elements -> ~64 MB of data (64 bytes per cache line * 1M lines)
    tab = (FFTSample*)aligned_alloc(32, m * sizeof(FFTSample));
    if (!tab) exit(1);

    for (int j = 0; j < m; j++) {
        tab[j] = (FFTSample)(j % 1000);
    }
}

void loop(); // forward declaration

__attribute__((constructor))
static void setup() {
    init_vars();
}