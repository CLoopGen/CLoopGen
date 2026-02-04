#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    real_t temp_a, temp_b, temp_c;
    for (int i = 0; i < 32000; i++) {
        temp_a = a[i];
        temp_b = b[i];
        temp_c = c[i];
        if (temp_a > temp_b) {
            a[i] = temp_a + temp_b * d[i];
            if (32000 > 10) {
                c[i] = temp_c + d[i] * d[i];
            } else {
                c[i] = d[i] * e[i] + (real_t)1.;
            }
        } else {
            b[i] = temp_a + e[i] * e[i];
            if (x > (real_t)0.) {
                c[i] = temp_a + d[i] * d[i];
            } else {
                c[i] = temp_c + e[i] * e[i];
            }
        }
    }
}
}
