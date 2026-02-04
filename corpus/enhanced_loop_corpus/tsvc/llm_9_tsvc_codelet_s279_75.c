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
for (int nl = 0; nl < 25000; nl++) {
    for (int i = 0; i < 16000; i++) {
        b[i] = -b[i] + d[i] * d[i];
        c[i] += d[i] * e[i];
        c[i] = (c[i] < 0.0f) ? -c[i] : c[i];
        a[i] = b[i] + c[i] * d[i] + e[i] * b[i] * 0.1f;
    }
    for (int i = 16000; i < 32000; i++) {
        if (a[i] > (real_t)0.) {
            c[i] = -c[i] + e[i] * e[i];
        } else {
            b[i] = -b[i] + d[i] * d[i];
            if (b[i] > a[i]) {
                c[i] += d[i] * e[i];
            }
        }
        a[i] = b[i] + c[i] * d[i];
    }
}
}
