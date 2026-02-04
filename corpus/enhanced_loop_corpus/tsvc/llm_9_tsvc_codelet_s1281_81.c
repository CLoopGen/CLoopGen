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
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 32000; i++) {
        x = b[i] * c[i] + a[i] * d[i] + e[i] * (real_t)0.5;
        a[i] = x - (real_t)1.5;
        b[i] = x + a[i] * c[i];
        c[i] = x * (real_t)0.9;
    }
}
}
