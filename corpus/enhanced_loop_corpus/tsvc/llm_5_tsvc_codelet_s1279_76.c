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
    for (int i = 0; i < 32000; i++) {
        int cond1 = a[i] < (real_t)0.;
        int cond2 = b[i] > a[i];
        if (!(cond1 && cond2)) {
            // Skip update, but keep execution path linearized with early exit
            continue;
        }
        c[i] += d[i] * e[i];
    }
}
}
