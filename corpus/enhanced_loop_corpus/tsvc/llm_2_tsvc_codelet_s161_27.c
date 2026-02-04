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
for (int nl = 0; nl < 100000 / 2; nl++) {
    for (int i = 0; i < 32000 - 1; i += 2) { // Strided access: step by 2
        if (b[i] < (real_t)0.) {
            goto L20;
        }
        a[i] = c[i] + d[i] * e[i];
        goto L10;
      L20:
        c[i + 1] = a[i] + d[i] * d[i];
      L10:
        ;
    }
}
}
