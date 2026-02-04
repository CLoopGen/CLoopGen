#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int nj = 0; nj < 32; nj++) {
        for (int nk = 0; nk < 1000; nk++) {
            int i = nj * 1000 + nk + 1;
            if (i < 32000) {
                a[i] += a[i - 1] * b[i];
            }
        }
    }
}
}
