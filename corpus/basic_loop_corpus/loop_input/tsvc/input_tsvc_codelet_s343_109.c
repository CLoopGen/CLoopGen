#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t flat_2d_array[65536];
__attribute__((aligned(64))) real_t aa[256][256];
__attribute__((aligned(64))) real_t bb[256][256];
int k;

void init_vars() {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            aa[j][i] = (real_t)(i + j);
            bb[j][i] = (real_t)((i - j) % 32 > 0 ? 1.0 : -1.0);
        }
    }
}