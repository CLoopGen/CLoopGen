#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    for (int i = 0; i < 32000 - 1; i++) {
        real_t temp = b[i] * b[i] + c[i] * c[i];
        a[i] = b[i] + c[i] + temp + temp * temp;
        d[i] = a[i] + a[i + 1] - b[i] * 0.5f;
    }
}
}
