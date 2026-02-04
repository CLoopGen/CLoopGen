#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern real_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    for (int i = 2; i < 31999; ++i) {
        t = a[i] + b[i] - c[i-1];
        a[i] = t + c[i - 1] * d[i];
        t = c[i] * d[i] + a[i];
        c[i] = t / (d[i] + 1e-6f);
        t = b[i] - a[i-1];
        b[i] = t * c[i+1];
    }
}
}
