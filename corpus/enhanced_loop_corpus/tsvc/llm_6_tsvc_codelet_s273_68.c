#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    real_t temp_a, temp_b, temp_c;
    for (int i = 0; i < 32000; i++) {
        temp_a = d[i] * e[i];
        a[i] += temp_a;
        temp_b = (a[i] < (real_t)0.) ? temp_a : 0.0f;
        b[i] += temp_b;
        c[i] += a[i] * d[i];
    }
}
}
