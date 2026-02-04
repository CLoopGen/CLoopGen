#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *window;
int i;
int n;
int n2;

void init_vars() {
    n = 1 << 20; // 1MB of floats: 2^20 * sizeof(float) = ~4MB
    n2 = n / 2;
    window = (float*)aligned_alloc(32, n * sizeof(float));
    for (i = 0; i < n; i++) {
        window[i] = (float)(i + 1);
    }
}