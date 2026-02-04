#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000; i += 4) {
        if (e[i] >= t) {
            a[i] += c[i] * d[i];
            b[i] += c[i] * c[i];
        }
        if (e[i+1] >= t) {
            a[i+1] += c[i+1] * d[i+1];
            b[i+1] += c[i+1] * c[i+1];
        }
        if (e[i+2] >= t) {
            a[i+2] += c[i+2] * d[i+2];
            b[i+2] += c[i+2] * c[i+2];
        }
        if (e[i+3] >= t) {
            a[i+3] += c[i+3] * d[i+3];
            b[i+3] += c[i+3] * c[i+3];
        }
    }
}
}
