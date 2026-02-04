#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t flat_2d_array[65536];
__attribute__((aligned(64))) real_t bb[256][256];
__attribute__((aligned(64))) real_t cc[256][256];
int k;

void init_vars() {
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            bb[i][j] = (real_t)(i + j);
            cc[i][j] = (real_t)(i * j + 1);
        }
    }

    for (int i = 0; i < 65536; ++i) {
        flat_2d_array[i] = (real_t)(i % 257);
    }

    k = 0;
}