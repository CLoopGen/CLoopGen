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
for (int nl = 0; nl < 200000; nl += 2) {
    for (int i = 0; i < 16000; i++) {
        int j = 2 * i;
        if (a[j] < (real_t)0.) {
            if (b[j] > a[j]) {
                c[j] += d[j] * e[j];
            }
        }
        if (a[j+1] < (real_t)0.) {
            if (b[j+1] > a[j+1]) {
                c[j+1] += d[j+1] * e[j+1];
            }
        }
    }
}
}
