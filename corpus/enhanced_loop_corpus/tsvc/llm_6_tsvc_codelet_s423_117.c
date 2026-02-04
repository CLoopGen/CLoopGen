#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    real_t temp = 0.0f;
    for (int i = 0; i < 32000 - 1; i++) {
        temp = xx[i] + a[i];  // Eliminate WAW and RAW on flat_2d_array by using local temp
        flat_2d_array[i + 1] = temp;
    }
    flat_2d_array[0] = temp;  // Introduce artificial loop-carried dependency via reuse of temp
}
}
