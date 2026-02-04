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
    for (int i = 0; i < 32000; i++) {
        int idx = (i * 17) % 32000;  // Strided, pseudo-random indirect access pattern with stride-like scattering
        if (a[idx] > (real_t)0.) {
            goto L20;
        }
        b[idx] = -b[idx] + d[idx] * e[idx];
        goto L30;
      L20:
        c[idx] = -c[idx] + d[idx] * e[idx];
      L30:
        a[idx] = b[idx] + c[idx] * d[idx];
    }
}
}
