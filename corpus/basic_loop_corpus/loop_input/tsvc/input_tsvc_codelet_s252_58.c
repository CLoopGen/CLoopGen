#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
real_t t;
real_t s;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 0.0f;
        b[i] = (real_t)(i + 1) * 0.5f;
        c[i] = (real_t)(i + 1) * 0.25f;
    }
    t = 0.0f;
    s = 0.0f;
}