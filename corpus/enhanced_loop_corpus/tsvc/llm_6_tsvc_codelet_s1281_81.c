#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    real_t temp_a, temp_b;
    for (int i = 0; i < 32000; i++) {
        temp_a = b[i] * c[i] + a[i] * d[i] + e[i];
        temp_b = temp_a - (real_t)1.;
        a[i] = temp_b;
        b[i] = temp_a;
    }
}
}
