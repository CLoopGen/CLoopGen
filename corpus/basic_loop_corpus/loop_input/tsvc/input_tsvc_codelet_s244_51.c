#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];

void init_vars() {
    for (int i = 0; i < 32000; ++i) {
        a[i] = (real_t)(i * 2) / 32000.0f;
        b[i] = (real_t)(i * 3) / 32000.0f;
        c[i] = (real_t)(i * 5) / 32000.0f;
        d[i] = (real_t)(i * 7) / 32000.0f;
    }
}