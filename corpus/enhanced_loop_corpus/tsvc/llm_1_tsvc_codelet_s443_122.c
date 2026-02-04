#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    int i = 0;
    for (; i < 32000 - 3; i += 4) {
        if (d[i] <= (real_t)0.) {
            a[i] += b[i] * c[i];
        } else {
            a[i] += b[i] * b[i];
        }
        if (d[i+1] <= (real_t)0.) {
            a[i+1] += b[i+1] * c[i+1];
        } else {
            a[i+1] += b[i+1] * b[i+1];
        }
        if (d[i+2] <= (real_t)0.) {
            a[i+2] += b[i+2] * c[i+2];
        } else {
            a[i+2] += b[i+2] * b[i+2];
        }
        if (d[i+3] <= (real_t)0.) {
            a[i+3] += b[i+3] * c[i+3];
        } else {
            a[i+3] += b[i+3] * b[i+3];
        }
    }
    for (; i < 32000; i++) {
        if (d[i] <= (real_t)0.) {
            a[i] += b[i] * c[i];
        } else {
            a[i] += b[i] * b[i];
        }
    }
}
}
