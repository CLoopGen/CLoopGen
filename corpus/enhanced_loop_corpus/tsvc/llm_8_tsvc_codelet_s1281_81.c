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
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 2) {
        real_t x1 = b[i] * c[i] + a[i] * d[i] + e[i];
        real_t x2 = b[i+1] * c[i+1] + a[i+1] * d[i+1] + e[i+1];
        a[i] = x1 - (real_t)1.;
        b[i] = x1;
        a[i+1] = x2 - (real_t)1.;
        b[i+1] = x2;
    }
}
}
