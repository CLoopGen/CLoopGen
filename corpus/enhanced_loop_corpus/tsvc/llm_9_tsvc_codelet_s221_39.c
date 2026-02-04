#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000 / 2; nl++) {
    for (int i = 1; i < 32000; i++) {
        real_t temp1 = c[i] * d[i];
        real_t temp2 = temp1 + a[i];
        a[i] = temp2;
        b[i] = b[i - 1] + temp2 + d[i] + c[i];
    }
}
}
