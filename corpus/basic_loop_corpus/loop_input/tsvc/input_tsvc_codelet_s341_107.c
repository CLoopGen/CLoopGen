#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
int j;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        b[i] = (i % 2 == 0) ? (real_t)(i + 1) : (real_t)(-1.0);
    }
}