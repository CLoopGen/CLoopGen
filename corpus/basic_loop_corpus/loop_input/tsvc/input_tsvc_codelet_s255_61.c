#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
real_t x;
real_t y;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        b[i] = (real_t)(i + 1) * (real_t)0.5;
    }
    x = (real_t)0.0;
    y = (real_t)0.0;
}