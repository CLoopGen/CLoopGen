#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t flat_2d_array[65536];
__attribute__((aligned(64))) real_t aa[256][256];
__attribute__((aligned(64))) real_t bb[256][256];
__attribute__((aligned(64))) real_t cc[256][256];
int k;

void init_vars() {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            aa[i][j] = 1.0f + i * 0.01f;
            bb[i][j] = 2.0f + j * 0.02f;
            cc[i][j] = 3.0f + (i * j) * 0.001f;
        }
    }
}