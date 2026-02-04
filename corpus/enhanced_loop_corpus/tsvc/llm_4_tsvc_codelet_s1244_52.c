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
    for (int i = 0; i < 32000 - 1; i++) {
        if (b[i] < c[i]) {
            a[i] = b[i] + c[i] * c[i] + b[i] * b[i] + c[i];
        } else {
            a[i] = b[i] * 2 + c[i] * 2;
        }
        d[i] = a[i] + a[i + 1];
    }
}
}
