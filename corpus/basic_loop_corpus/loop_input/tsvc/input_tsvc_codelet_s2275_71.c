#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t aa[256][256];
__attribute__((aligned(64))) real_t bb[256][256];
__attribute__((aligned(64))) real_t cc[256][256];

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 0.0f;
        b[i] = 1.0f + i * 0.0001f;
        c[i] = 2.0f + i * 0.0002f;
        d[i] = 3.0f + i * 0.0003f;
    }

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            aa[j][i] = 0.0f;
            bb[j][i] = 1.0f + (i * 256 + j) * 0.0001f;
            cc[j][i] = 2.0f + (i * 256 + j) * 0.0002f;
        }
    }
}