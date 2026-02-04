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
for (int nl = 0; nl < 50000; nl++) {
    real_t s1 = (real_t)0.;
    real_t s2 = (real_t)1.;
    for (int i = 0; i < 32000; i++) {
        a[i] = s1 * e[i] + s2 * d[i];
        s1 = b[i] + c[i] - a[i];
        s2 = b[i] * c[i] + a[i];
        b[i] = a[i] + d[i] + e[i];
    }
}
}
