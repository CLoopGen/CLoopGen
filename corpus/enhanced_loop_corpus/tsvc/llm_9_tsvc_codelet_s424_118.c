#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 32000 - 1; i++) {
        real_t temp1 = flat_2d_array[i] + a[i];
        real_t temp2 = flat_2d_array[i] * a[i];
        xx[i + 1] = temp1 + temp2; // Increased computational intensity with multiply-add
    }
}
}
