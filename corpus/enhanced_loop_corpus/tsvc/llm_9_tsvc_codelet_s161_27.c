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
for (int nl = 0; nl < 100000 / 8; nl++) {
    for (int i = 0; i < 16000 - 1; ++i) {
        if (b[i] < (real_t)0.) {
            goto L20;
        }
        a[i] = c[i] + d[i] * e[i];
        a[i + 16000] = c[i + 16000] + d[i + 16000] * e[i + 16000];
        goto L10;
      L20:
        c[i + 1] = a[i] + d[i] * d[i];
      L10:
        ;
    }
}
}
