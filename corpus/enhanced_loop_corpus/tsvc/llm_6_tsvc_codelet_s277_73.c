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
        real_t temp_a = a[i];
        real_t temp_b = b[i];
        real_t temp_c = c[i];
        real_t temp_d = d[i];
        real_t temp_e = e[i];

        if (temp_a >= (real_t)0.) {
            goto L20;
        }
        if (temp_b >= (real_t)0.) {
            goto L30;
        }
        a[i] = temp_a + temp_c * temp_d;
      L30:
        b[i + 1] = temp_c + temp_d * temp_e;
      L20:
        ;
    }
}
}
