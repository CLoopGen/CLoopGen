#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t e[32000];
__attribute__((aligned(64))) real_t aa[256][256];
real_t s;

void init_vars() {
    for (int i = 0; i < 32000; ++i) {
        a[i] = (real_t)(i % 2 ? 1.5f : -0.5f);
        c[i] = (real_t)(i + 1) * 0.1f;
        d[i] = (real_t)(i) * 0.05f;
        b[i] = 0.0f;
        e[i] = 0.0f;
    }
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            aa[i][j] = (real_t)(i * 256 + j) * 0.01f;
        }
    }
    s = 0.0f;
}