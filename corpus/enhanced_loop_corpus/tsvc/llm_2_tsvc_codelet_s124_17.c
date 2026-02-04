#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    j = -1;
    for (int i = 0; i < 32000; i += 4) {
        for (int k = 0; k < 4 && (i + k) < 32000; k++) {
            int idx = i + k;
            if (b[idx] > (real_t)0.) {
                j++;
                a[j] = b[idx] + d[idx] * e[idx];
            } else {
                j++;
                a[j] = c[idx] + d[idx] * e[idx];
            }
        }
    }
}
}
