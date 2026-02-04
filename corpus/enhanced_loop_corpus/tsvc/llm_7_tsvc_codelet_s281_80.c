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
    #pragma unroll(8)
    for (int i = 0; i < 32000; i += 8) {
        real_t temp_x[8];
        for (int j = 0; j < 8; j++) {
            if (i + j < 32000) {
                temp_x[j] = a[32000 - (i + j) - 1] + b[i + j] * c[i + j];
                a[i + j] = temp_x[j] - (real_t)1.;
                b[i + j] = temp_x[j];
            }
        }
    }
}
}
