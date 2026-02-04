#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int nj = 0; nj < 16; nj++) {
        for (int i = 0; i < 2000; i++) {
            int idx = nj * 2000 + i;
            x = a[32000 - idx - 1] + b[idx] * c[idx];
            a[idx] = x - (real_t)1.;
            b[idx] = x;
        }
    }
}
}
