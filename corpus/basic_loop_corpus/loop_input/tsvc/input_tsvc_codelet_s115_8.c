#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t aa[256][256];

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f + i * 0.001f;
    }
    for (int j = 0; j < 256; j++) {
        for (int i = 0; i < 256; i++) {
            aa[j][i] = (i >= j + 1) ? (1.0f / (1.0f + i - j)) : 0.0f;
        }
    }
}