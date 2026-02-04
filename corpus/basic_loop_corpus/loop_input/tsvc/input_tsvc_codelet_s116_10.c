#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f + (i % 100) * 0.01f;
    }
}