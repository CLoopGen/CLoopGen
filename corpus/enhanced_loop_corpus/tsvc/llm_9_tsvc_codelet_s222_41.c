#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000 / 2; nl += 2) {
    for (int i = 1; i < 16000; i++) {
        a[i] += b[i] * c[i];
        e[i] = e[i - 1] * e[i - 1];
        a[i] -= b[i] * c[i];
    }
    for (int i = 16000; i < 32000; i++) {
        a[i] += b[i] * c[i] * 0.5f;
        e[i] = e[i - 1] * e[i - 1] * 1.1f;
        a[i] -= b[i] * c[i] * 0.5f;
    }
}
}
