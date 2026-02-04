#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t e[32000];
int j;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        b[i] = 1.0f + i * 0.0001f;
        c[i] = 2.0f + i * 0.0002f;
        d[i] = 3.0f + i * 0.0003f;
        e[i] = 4.0f + i * 0.0004f;
        a[i] = 0.0f;
    }
    j = 0;
}