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
    real_t temp_a, temp_b;
    for (int i = 1; i < 32000 - 1; i++) {
        temp_a = b[i - 1] + c[i] * d[i];
        temp_b = b[i + 1] - e[i] * d[i];
        a[i] = temp_a;
        b[i] = temp_b;
    }
}
}
