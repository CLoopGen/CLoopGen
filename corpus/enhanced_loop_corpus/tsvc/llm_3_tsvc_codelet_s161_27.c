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
    for (int i = 0; i < 32000 - 1; ++i) {
        int idx = (i * 17) % 31999; // Indirect access via scrambled index (within bounds)
        if (b[idx] < (real_t)0.) {
            goto L20;
        }
        a[idx] = c[idx] + d[idx] * e[idx];
        goto L10;
      L20:
        c[idx + 1] = a[idx] + d[idx] * d[idx];
      L10:
        ;
    }
}
}
