#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
real_t sum;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i % 1000) / 10.0f;
    }
    sum = 0.0;
}