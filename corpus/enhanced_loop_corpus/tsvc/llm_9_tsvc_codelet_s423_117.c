#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 16000 - 1; i++) {
        real_t temp1 = xx[i] * a[i] + xx[i] + a[i];       // Increased arithmetic intensity
        real_t temp2 = xx[i + 16000] * a[i + 16000] + xx[i + 16000] + a[i + 16000];
        flat_2d_array[i + 1] = temp1;
        flat_2d_array[i + 16001] = temp2;
    }
}
}
