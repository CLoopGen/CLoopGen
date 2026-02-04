#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000 / 4; nl++) {
    for (int i = 3; i < 32000; i++) {
        a[i] = a[i] + a[i - 1] * b[i] + a[i - 2] * c[i] + a[i - 3] * b[i-1];
    }
}
}
