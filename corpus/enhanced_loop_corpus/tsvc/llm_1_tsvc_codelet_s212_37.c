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
    for (int nj = 0; nj < 16000; nj++) {
        for (int i = 0; i < 2; i++) {
            int idx = nj * 2 + i;
            if (idx < 32000 - 1) {
                a[idx] *= c[idx];
                b[idx] += a[idx + 1] * d[idx];
            }
        }
    }
}
}
