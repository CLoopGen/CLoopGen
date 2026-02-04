#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    real_t temp_b = b[0];
    for (int i = 1; i < 32000; i++) {
        a[i] += c[i] * d[i];
        temp_b += a[i] + d[i];
        b[i] = temp_b;
    }
}
}
