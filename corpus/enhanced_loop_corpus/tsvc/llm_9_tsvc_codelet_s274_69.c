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
for (int nl = 0; nl < 200000; nl++) {
    for (int i = 0; i < 16000; i++) {
        real_t prod1 = d[i] * e[i];
        real_t sum1 = c[i] + prod1;
        a[i] = sum1;
        if (a[i] > (real_t)0.) {
            b[i] = b[i] + a[i] * (real_t)1.2;
        } else {
            a[i] = prod1 * (real_t)1.1;
            b[i] = b[i] + a[i] * (real_t)0.9;
        }
        real_t temp = a[i] + b[i];
        a[i] = temp * (real_t)0.5;
    }
}
}
