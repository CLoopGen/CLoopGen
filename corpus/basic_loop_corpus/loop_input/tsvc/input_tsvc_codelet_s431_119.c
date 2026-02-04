#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
int k;

void init_vars() {
    k = 1;
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i % 100) * 0.1f;
        b[i] = (real_t)((i + 1) % 75) * 0.2f;
    }
}