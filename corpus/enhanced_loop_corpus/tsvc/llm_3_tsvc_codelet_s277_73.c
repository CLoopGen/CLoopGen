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
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000 - 1; i++) {
        int idx = 31999 - i;
        if (a[idx] >= (real_t)0.) {
            goto L20;
        }
        if (b[idx] >= (real_t)0.) {
            goto L30;
        }
        a[idx] += c[idx] * d[idx];
      L30:
        b[idx + 1] = c[idx] + d[idx] * e[idx];
      L20:
        ;
    }
}
}
