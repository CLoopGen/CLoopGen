#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    for (int i = 2; i < 32000 - 2; i++) {
        a[i] = b[i - 1] + c[i] - d[i + 1];
        b[i] = (a[i + 1] * d[i]) + c[i - 2];
        c[i] = a[i] * b[i] - d[i];
    }
}
}
