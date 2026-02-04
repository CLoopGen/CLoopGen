#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t bb[256][256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 400 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        k = (i + 1) * i / 2 + i;
        for (int j = i; j < 256; j++) {
            flat_2d_array[k] += bb[j][i] * 2.0f;
            k += j + 1;
            flat_2d_array[k % 65536] += bb[i][j] * 0.5f;
        }
    }
}
}
