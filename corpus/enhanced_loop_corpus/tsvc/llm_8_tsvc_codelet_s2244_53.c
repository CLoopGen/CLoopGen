#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    for (int i = 0; i < 32000 - 2; i++) {
        a[i + 2] = b[i] + e[i] * c[i] - e[i+1] * b[i+1];
        a[i + 1] = b[i] + e[i] + c[i] * b[i];
        a[i] = b[i] + c[i];
    }
}
}
