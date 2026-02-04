#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
int inc;

void init_vars() {
    inc = 1;
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i * 2);
        b[i] = (real_t)(i * 3);
    }
}