#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
int M;

void init_vars() {
    M = 16000;
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i % 123);
        b[i] = (real_t)(i % 456);
    }
}