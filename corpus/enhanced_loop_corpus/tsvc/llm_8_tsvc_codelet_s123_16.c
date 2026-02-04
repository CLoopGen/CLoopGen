#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    j = -1;
    for (int i = 0; i < (32000 / 4); i++) {
        j++;
        a[j] = b[i] + d[i] * e[i];
        if (c[i] > (real_t)0.) {
            j++;
            a[j] = c[i] + d[i] * e[i];
        }
        // Additional computational work to increase intensity
        d[i] = d[i] * (real_t)1.05 + (real_t)0.01;
        e[i] = e[i] * (real_t)0.95 - (real_t)0.01;
    }
}
}
