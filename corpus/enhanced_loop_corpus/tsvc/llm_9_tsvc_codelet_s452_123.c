#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 16000; i++) {
        real_t idx1 = (real_t)(i + 1);
        real_t idx2 = (real_t)(i + 2);
        a[i] = b[i] + c[i] * idx1 + c[i] * idx1 * idx2 / 2.0f;
        a[31999 - i] = b[31999 - i] + c[31999 - i] * idx1;
    }
}
}
