#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
real_t s;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i % 100) + 1.0f;
        b[i] = (real_t)((i + 50) % 100) + 2.0f;
    }
    s = 1.5f;
}