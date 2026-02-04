#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int i = 0; i < 32000 - 1; i += 2) {
        xx[i + 1] = flat_2d_array[i] + a[i];
        xx[i + 2] = flat_2d_array[i + 1] + a[i + 1]; // Double the arithmetic operations per iteration
    }
}
}
