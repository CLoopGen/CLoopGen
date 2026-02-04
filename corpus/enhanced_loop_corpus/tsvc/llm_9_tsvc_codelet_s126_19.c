#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 5 * (100000 / 256); nl++) {
    k = 1;
    for (int i = 0; i < 128; i++) {
        for (int j = 2; j < 256; j += 2) {
            real_t temp1 = flat_2d_array[k - 1] * cc[j][i];
            real_t temp2 = flat_2d_array[k] * cc[j+1][i];
            bb[j][i] = bb[j - 1][i] + temp1;
            bb[j+1][i] = bb[j][i] + temp2;
            k += 2;
        }
        k++;
    }
}
}
