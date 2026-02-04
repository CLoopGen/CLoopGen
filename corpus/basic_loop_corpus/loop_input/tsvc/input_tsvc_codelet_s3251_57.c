#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t e[32000];

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f + i * 0.0001f;
        b[i] = 2.0f + i * 0.0002f;
        c[i] = 3.0f + i * 0.0003f;
        d[i] = 4.0f + i * 0.0004f;
        e[i] = 5.0f + i * 0.0005f;
    }
}