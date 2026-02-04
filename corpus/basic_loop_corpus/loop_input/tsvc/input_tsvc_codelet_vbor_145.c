#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t x[32000];
__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t e[32000];
__attribute__((aligned(64))) real_t aa[256][256];

real_t a1;
real_t b1;
real_t c1;
real_t d1;
real_t e1;
real_t f1;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f + 0.01f * (i % 100);
        b[i] = 1.0f + 0.02f * (i % 99);
        c[i] = 1.0f + 0.03f * (i % 98);
        d[i] = 1.0f + 0.04f * (i % 97);
        e[i] = 1.0f + 0.05f * (i % 96);
        if (i < 256) {
            x[i] = 0.0f;
        }
    }

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            aa[i][j] = 1.0f + 0.06f * ((i + j) % 95);
        }
    }

    a1 = 1.0f;
    b1 = 1.0f;
    c1 = 1.0f;
    d1 = 1.0f;
    e1 = 1.0f;
    f1 = 1.0f;
}