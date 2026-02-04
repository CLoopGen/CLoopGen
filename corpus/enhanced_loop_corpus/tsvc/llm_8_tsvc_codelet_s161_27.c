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
for (int nl = 0; nl < 100000 / 4; nl++) {
    for (int i = 0; i < 32000 - 2; i += 2) {
        if (b[i] < (real_t)0.) {
            goto L20;
        }
        a[i] = c[i] + d[i] * e[i] + d[i] * c[i];
        a[i+1] = c[i+1] + d[i+1] * e[i+1] + d[i+1] * c[i+1];
        goto L10;
      L20:
        c[i + 1] = a[i] + d[i] * d[i];
        c[i + 2] = a[i+1] + d[i+1] * d[i+1];
      L10:
        ;
    }
}
}
