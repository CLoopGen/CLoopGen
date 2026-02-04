#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t FFTSample;

FFTSample *output;
int k;
int n;
int n2;
int n4;

void init_vars() {
    n = 1 << 20; // 1 million elements, adjust for ~0.01 sec runtime
    n2 = n / 2;
    n4 = n / 4;

    output = (FFTSample*)aligned_alloc(32, n * sizeof(FFTSample));
    if (!output) exit(1);

    for (int i = 0; i < n; i++) {
        output[i] = rand() % 1000;
    }
}