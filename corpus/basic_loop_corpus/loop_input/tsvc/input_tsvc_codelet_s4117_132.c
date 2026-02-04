#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 0.0f;
        b[i] = (real_t)(i % 123);
        d[i] = (real_t)(i % 456);
    }
    for (int i = 0; i < 32000; i++) {
        c[i] = (real_t)(i % 789);
    }
}