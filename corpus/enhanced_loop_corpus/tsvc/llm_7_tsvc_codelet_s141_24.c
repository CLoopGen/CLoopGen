#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t bb[256][256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (int nl = 0; nl < 200 * (100000 / 256); nl++) {
        for (int i = 0; i < 256; i++) {
            int base = (i + 1) * i / 2 + i;
            int k_local = base;
            for (int j = i; j < 256; j++) {
                real_t temp_sum = flat_2d_array[k_local] + bb[j][i];
                flat_2d_array[k_local] = temp_sum;
                k_local += j + 1;
            }
        }
    }
}
