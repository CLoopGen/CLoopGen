#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 4 * 100000; nl++) {
        for (int nj = 0; nj < 1000; nj++) {
            for (int i = 0; i < 32; i++) {
                int idx = (nj * 32) + i;
                a[idx] += b[idx] * c[idx];
            }
        }
    }
}
