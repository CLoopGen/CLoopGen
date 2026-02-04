#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t e[32000];
real_t x;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f + i * 0.01f;
        b[i] = 2.0f + i * 0.02f;
        c[i] = 3.0f + i * 0.03f;
        d[i] = 4.0f + i * 0.04f;
        e[i] = 5.0f + i * 0.05f;
    }
    x = 0.0f;
}