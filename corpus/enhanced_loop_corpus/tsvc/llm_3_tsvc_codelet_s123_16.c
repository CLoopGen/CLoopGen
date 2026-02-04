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
    // Consecutive write pattern with reversed read order
    for (int i = (32000 / 2) - 1; i >= 0; i--) {
        j++;
        a[j] = b[i] + d[i] * e[i];
        if (c[i] > (real_t)0.) {
            j++;
            a[j] = c[i] + d[i] * e[i];
        }
    }
}
}
