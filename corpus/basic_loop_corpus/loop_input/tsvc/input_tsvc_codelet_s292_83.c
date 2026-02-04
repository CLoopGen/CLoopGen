#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
int im1;
int im2;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i % 100) * 0.1f;
        b[i] = (real_t)((i + 42) % 200) * 0.05f;
    }
    im1 = 0;
    im2 = 0;
}