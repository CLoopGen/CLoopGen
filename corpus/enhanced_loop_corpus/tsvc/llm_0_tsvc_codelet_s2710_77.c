#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    for (int i = 0; i < 32000; i += 4) {
        for (int j = 0; j < 4 && (i + j) < 32000; j++) {
            int idx = i + j;
            if (a[idx] > b[idx]) {
                a[idx] += b[idx] * d[idx];
                if (32000 > 10) {
                    c[idx] += d[idx] * d[idx];
                } else {
                    c[idx] = d[idx] * e[idx] + (real_t)1.;
                }
            } else {
                b[idx] = a[idx] + e[idx] * e[idx];
                if (x > (real_t)0.) {
                    c[idx] = a[idx] + d[idx] * d[idx];
                } else {
                    c[idx] += e[idx] * e[idx];
                }
            }
        }
    }
}
}
