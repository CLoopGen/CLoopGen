#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t e[32000];
__attribute__((aligned(64))) int indx[32000];

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i + 1);
        b[i] = (real_t)(i * 1.5f);
        c[i] = (real_t)(i * 2.5f);
        d[i] = (real_t)(i * 3.5f);
        e[i] = (real_t)(i * 4.5f);
        indx[i] = (i % 4) + 1;
    }
}