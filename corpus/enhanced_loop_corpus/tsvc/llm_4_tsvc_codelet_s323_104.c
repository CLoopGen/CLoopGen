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
for (int nl = 0; nl < 100000 / 2; nl++) {
    for (int i = 1; i < 32000; i++) {
        if (c[i] > 0.0f) {
            a[i] = b[i - 1] + c[i] * d[i];
            b[i] = a[i] + c[i] * e[i];
        } else {
            a[i] = b[i - 1];
            b[i] = a[i];
        }
    }
}
}
