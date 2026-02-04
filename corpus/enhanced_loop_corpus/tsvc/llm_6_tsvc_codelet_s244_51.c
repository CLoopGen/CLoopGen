#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000 - 1; ++i) {
        real_t temp1 = c[i] * d[i];
        a[i] = b[i] + temp1;
        real_t temp2 = c[i] + b[i];
        b[i] = temp2;
        real_t temp3 = a[i + 1] * d[i];
        a[i + 1] = temp2 + temp3;
    }
}
}
