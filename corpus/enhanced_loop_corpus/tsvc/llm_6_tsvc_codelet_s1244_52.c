#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000 - 1; i++) {
        real_t temp_c_sq = c[i] * c[i];
        real_t temp_b_sq = b[i] * b[i];
        a[i] = b[i] + temp_c_sq + temp_b_sq + c[i];
    }
    for (int i = 0; i < 32000 - 1; i++) {
        d[i] = a[i] + a[i + 1];
    }
}
}
