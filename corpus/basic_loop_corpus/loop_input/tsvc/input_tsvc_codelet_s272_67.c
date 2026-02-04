#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t e[32000];
int t;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f;
        c[i] = 0.5f;
        d[i] = 1.5f;
        e[i] = i % 2 ? 50.0f : 150.0f;
    }
    t = 100;
}