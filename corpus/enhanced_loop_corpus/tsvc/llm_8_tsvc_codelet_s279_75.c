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
for (int nl = 0; nl < 50000; nl++) {
    for (int i = 0; i < 32000; i += 2) {
        if (a[i] > (real_t)0.) {
            goto L20;
        }
        b[i] = -b[i] + d[i] * d[i];
        if (b[i] <= a[i]) {
            goto L30;
        }
        c[i] += d[i] * e[i] + d[i] * d[i] * 0.5f;
        goto L30;
      L20:
        c[i] = -c[i] + e[i] * e[i] + e[i] * d[i];
      L30:
        a[i] = b[i] + c[i] * d[i];
        a[i+1] = b[i+1] + c[i+1] * d[i+1];
    }
}
}
