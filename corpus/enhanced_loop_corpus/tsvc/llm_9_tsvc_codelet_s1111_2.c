#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl += 2) {
    for (int i = 0; i < 32000 / 2; i++) {
        real_t temp1 = c[i] * b[i];
        real_t temp2 = d[i] * b[i];
        real_t temp3 = c[i] * c[i];
        real_t temp4 = d[i] * c[i];
        a[2 * i] = temp1 + temp2 + temp3 + temp2 + temp4 + temp1 + temp3;
    }
}
}
