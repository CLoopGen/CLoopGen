#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000; i += 4) {
        #pragma unroll(4)
        for (int j = 0; j < 4 && (i + j) < 32000; j++) {
            int idx = i + j;
            real_t val = a[idx] - b[idx] * d[idx];
            if (a[idx] > b[idx]) {
                c[idx] += val;
                a[idx] = val;
            }
        }
    }
}
}
