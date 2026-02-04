#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000 / 4; nl++) {
    for (int i = 2; i < 31999; i++) {
        a[i] += b[i] * c[i] + b[i-1] * c[i+1];
        e[i] = e[i - 1] * e[i - 1] + e[i] * e[i + 1];
        a[i] -= b[i] * c[i] - b[i+1] * c[i-1];
        a[i] += b[i] * c[i-1];
    }
}
}
