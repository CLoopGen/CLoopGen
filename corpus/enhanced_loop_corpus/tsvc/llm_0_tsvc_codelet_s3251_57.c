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
    for (int nj = 0; nj < 4; nj++) {
        for (int i = 0; i < 8000 - 1; i++) {
            int idx = nj * 8000 + i;
            a[idx + 1] = b[idx] + c[idx];
            b[idx] = c[idx] * e[idx];
            d[idx] = a[idx] * e[idx];
        }
    }
}
}
