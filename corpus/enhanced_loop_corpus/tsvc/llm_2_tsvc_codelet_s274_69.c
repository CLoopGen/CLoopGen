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
    for (int i = 0; i < 32000; i += 4) {
        a[i] = c[i] + e[i] * d[i];
        if (a[i] > (real_t)0.) {
            b[i] = a[i] + b[i];
        } else {
            a[i] = d[i] * e[i];
        }
        if (i+1 < 32000) {
            a[i+1] = c[i+1] + e[i+1] * d[i+1];
            if (a[i+1] > (real_t)0.) {
                b[i+1] = a[i+1] + b[i+1];
            } else {
                a[i+1] = d[i+1] * e[i+1];
            }
        }
        if (i+2 < 32000) {
            a[i+2] = c[i+2] + e[i+2] * d[i+2];
            if (a[i+2] > (real_t)0.) {
                b[i+2] = a[i+2] + b[i+2];
            } else {
                a[i+2] = d[i+2] * e[i+2];
            }
        }
        if (i+3 < 32000) {
            a[i+3] = c[i+3] + e[i+3] * d[i+3];
            if (a[i+3] > (real_t)0.) {
                b[i+3] = a[i+3] + b[i+3];
            } else {
                a[i+3] = d[i+3] * e[i+3];
            }
        }
    }
}
}
