#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
real_t x;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(32000 - i);
    }
    x = 0.0f;
}