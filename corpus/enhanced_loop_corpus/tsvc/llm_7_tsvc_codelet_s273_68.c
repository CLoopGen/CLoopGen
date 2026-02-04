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
    real_t prev_a, new_a;
    prev_a = a[0];
    for (int i = 1; i < 32000; i++) {
        new_a = a[i];
        a[i] += d[i] * e[i];
        if (prev_a < (real_t)0.)
            b[i] += d[i-1] * e[i-1];
        c[i] += new_a * d[i];
        prev_a = new_a;
    }
    // Handle first element separately to maintain loop-carried dependency chain
    a[0] += d[0] * e[0];
    if (a[31999] < (real_t)0.)
        b[0] += d[31999] * e[31999];
    c[0] += a[0] * d[0];
}
}
