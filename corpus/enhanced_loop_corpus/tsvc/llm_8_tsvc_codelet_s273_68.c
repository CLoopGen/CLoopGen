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
    for (int i = 0; i < 32000; i += 2) {
        real_t de0 = d[i] * e[i];
        real_t de1 = d[i+1] * e[i+1];
        a[i] += de0;
        a[i+1] += de1;
        if (a[i] < (real_t)0.)
            b[i] += de0;
        if (a[i+1] < (real_t)0.)
            b[i+1] += de1;
        c[i] += a[i] * d[i];
        c[i+1] += a[i+1] * d[i+1];
    }
}
}
