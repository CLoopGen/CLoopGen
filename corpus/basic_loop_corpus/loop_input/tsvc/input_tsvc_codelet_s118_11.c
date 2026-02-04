#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t bb[256][256];

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f + (i % 7) * 0.1f;
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            bb[i][j] = 0.01f * ((i + j) % 13);
        }
    }
}