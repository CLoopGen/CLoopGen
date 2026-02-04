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
        a[i] = 0.0f;
        b[i] = 0.0f;
        c[i] = 0.0f;
        d[i] = 0.0f;
        e[i] = 0.0f;
    }
}