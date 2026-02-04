#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t e[32000];

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i * 0.1);
        b[i] = (real_t)(i * 0.2);
        c[i] = (real_t)(i * 0.3);
        d[i] = (real_t)(i * 0.4);
        e[i] = (real_t)(i * 0.5);
    }
}