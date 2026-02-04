#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t aa[256][256];
__attribute__((aligned(64))) real_t bb[256][256];
__attribute__((aligned(64))) real_t cc[256][256];

void init_vars() {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            aa[i][j] = (real_t)(i * 256 + j + 1);
            bb[i][j] = (real_t)(i * 256 + j + 2);
            cc[i][j] = (real_t)(i * 256 + j + 3);
        }
    }
}