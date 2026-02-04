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
    real_t temp_b, temp_c;
    for (int i = 0; i < 32000; i++) {
        temp_b = b[i];
        temp_c = c[i];

        if (a[i] > (real_t)0.) {
            temp_c = -temp_c + d[i] * e[i];
        } else {
            temp_b = -temp_b + d[i] * e[i];
        }

        a[i] = temp_b + temp_c * d[i];
        b[i] = temp_b;
        c[i] = temp_c;
    }
}
}
