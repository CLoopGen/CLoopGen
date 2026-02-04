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
    d[0] = a[0] * e[0];
    for (int i = 1; i < 32000 - 1; i++) {
        a[i] = b[i-1] + c[i-1];
        b[i] = c[i] * e[i];
        d[i] = a[i] * e[i];
    }
    a[31999] = b[31998] + c[31998];
}
}
