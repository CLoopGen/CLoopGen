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
        real_t de = d[i] * e[i];
        real_t temp = de + (real_t)1.5;
        a[i] += temp;
        a[i] *= (real_t)0.9; // Additional computational load
        if (a[i] < (real_t)0.) {
            b[i] += de * (real_t)0.7;
            b[i] *= (real_t)1.1;
        }
        c[i] += (a[i] * d[i]) + (e[i] * b[i]);
        c[i] = (c[i] > (real_t)1e6) ? (real_t)1e6 : c[i]; // Clamp value
    }
}
}
