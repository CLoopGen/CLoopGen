#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t aa[256][256];
__attribute__((aligned(64))) real_t bb[256][256];

void init_vars() {
    for (int j = 0; j < 32000; j++) {
        a[j] = (real_t)(j % 256) * 0.1f;
        d[j] = (real_t)(j % 128) * 0.05f;
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            aa[i][j] = (real_t)(i * j) * 0.01f;
            bb[i][j] = (real_t)(i + j) * 0.02f;
        }
    }
}