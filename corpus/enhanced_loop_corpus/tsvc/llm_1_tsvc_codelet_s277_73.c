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
    int i = 0;
    for (; i < 32000 - 1; ) {
        if (a[i] >= (real_t)0.) {
            i++;
            continue;
        }
        if (b[i] >= (real_t)0.) {
            b[i + 1] = c[i] + d[i] * e[i];
            i++;
            continue;
        }
        a[i] += c[i] * d[i];
        b[i + 1] = c[i] + d[i] * e[i];
        i++;
    }
}
}
