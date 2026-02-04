#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t aa[256][256];
__attribute__((aligned(64))) real_t bb[256][256];

void init_vars() {
    for (int i = 0; i < 256; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f;
        c[i] = 0.5f;
        for (int j = 0; j < 256; j++) {
            aa[j][i] = (j == 0) ? 1.0f : 0.0f;
            bb[j][i] = 1.0f;
        }
    }
}