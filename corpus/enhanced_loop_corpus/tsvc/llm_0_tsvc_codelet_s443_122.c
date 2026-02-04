#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 4) {
        for (int j = 0; j < 4 && (i + j) < 32000; j++) {
            if (d[i + j] <= (real_t)0.) {
                goto L20;
            } else {
                goto L30;
            }
          L20:
            a[i + j] += b[i + j] * c[i + j];
            goto L50;
          L30:
            a[i + j] += b[i + j] * b[i + j];
          L50:
            ;
        }
    }
}
}
