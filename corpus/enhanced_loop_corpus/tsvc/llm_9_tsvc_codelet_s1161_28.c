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
    for (int i = 0; i < 16000 - 1; ++i) {
        if (c[i] < (real_t)0.) {
            goto L20;
        }
        a[i] = c[i] + d[i] * e[i] - d[i] + e[i] * e[i];
        goto L10;
      L20:
        b[i] = a[i] + d[i] * d[i] + c[i] * c[i];
      L10:
        ;
    }
}
}
