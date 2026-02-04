#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
real_t alpha;

void init_vars() {
    alpha = 1.5f;
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i % 100) * 0.1f;
        b[i] = (real_t)((i + 10) % 75) * 0.2f;
    }
}