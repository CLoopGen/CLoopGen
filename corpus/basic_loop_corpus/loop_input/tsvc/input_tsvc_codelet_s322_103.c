#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f + i * 0.0001f;
        b[i] = 0.5f - i * 0.00001f;
        c[i] = 0.25f + i * 0.000005f;
    }
}