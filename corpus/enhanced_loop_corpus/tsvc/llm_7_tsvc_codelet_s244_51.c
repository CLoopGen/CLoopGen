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
        a[i] = b[i] + c[i] * d[i];
    }
    for (int i = 0; i < 32000 - 1; ++i) {
        b[i] = c[i] + b[i];
    }
    for (int i = 0; i < 32000 - 1; ++i) {
        a[i + 1] = b[i] + a[i + 1] * d[i];
    }
}
}
