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
    for (int i = 0; i < 320; i++) {
        for (int k = 0; k < 100; k++) {
            int idx = i * 100 + k;
            a[idx] = 1 + idx;
            b[idx] = 2 + idx;
            c[idx] = 3 + idx;
            d[idx] = 4 + idx;
            e[idx] = 5 + idx;
        }
    }
}
