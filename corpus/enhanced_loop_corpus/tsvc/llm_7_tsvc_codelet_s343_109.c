#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * (100000 / 256); nl++) {
    int temp_k = 0;
    real_t temp_array[65536];
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            if (bb[j][i] > (real_t)0.) {
                temp_array[temp_k++] = aa[j][i];
            }
        }
    }
    for (int idx = 0; idx < temp_k; idx++) {
        flat_2d_array[idx] = temp_array[idx];
    }
    k = temp_k - 1;
}
}
