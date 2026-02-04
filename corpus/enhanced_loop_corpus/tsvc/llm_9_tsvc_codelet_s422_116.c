#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 16 * 100000; nl++) {
    for (int i = 0; i < 32000; i++) {
        real_t temp1 = flat_2d_array[i + 8] + a[i];
        real_t temp2 = flat_2d_array[i + 16] * 0.5f;
        xx[i] = temp1 + temp2 - flat_2d_array[i];
    }
}
}
