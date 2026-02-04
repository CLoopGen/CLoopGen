#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
real_t s;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f + i * 0.1f;
        c[i] = 3.0f - i * 0.05f;
        d[i] = 0.5f + i * 0.01f;
    }
    s = 0.0f;
}