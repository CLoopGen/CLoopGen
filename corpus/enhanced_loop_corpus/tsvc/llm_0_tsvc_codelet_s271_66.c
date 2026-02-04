#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 8) {
        if (b[i] > (real_t)0.) {
            a[i] += b[i] * c[i];
        }
        if (b[i+1] > (real_t)0. && i+1 < 32000) {
            a[i+1] += b[i+1] * c[i+1];
        }
        if (b[i+2] > (real_t)0. && i+2 < 32000) {
            a[i+2] += b[i+2] * c[i+2];
        }
        if (b[i+3] > (real_t)0. && i+3 < 32000) {
            a[i+3] += b[i+3] * c[i+3];
        }
        if (b[i+4] > (real_t)0. && i+4 < 32000) {
            a[i+4] += b[i+4] * c[i+4];
        }
        if (b[i+5] > (real_t)0. && i+5 < 32000) {
            a[i+5] += b[i+5] * c[i+5];
        }
        if (b[i+6] > (real_t)0. && i+6 < 32000) {
            a[i+6] += b[i+6] * c[i+6];
        }
        if (b[i+7] > (real_t)0. && i+7 < 32000) {
            a[i+7] += b[i+7] * c[i+7];
        }
    }
}
}
