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
for (int nl = 0; nl < 200000; nl++) {
    j = -1;
    for (int i = 0; i < (32000 / 8); i++) {
        j++;
        real_t de = d[i] * e[i]; // Reuse common subexpression
        a[j] = b[i] + de;
        if (c[i] > (real_t)0.) {
            j++;
            a[j] = c[i] + de;
        }
        // Add extra arithmetic to increase compute per iteration
        b[i] = (b[i] + c[i]) * (real_t)0.5;
    }
}
}
