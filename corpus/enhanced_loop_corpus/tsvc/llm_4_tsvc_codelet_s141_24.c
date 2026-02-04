#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t bb[256][256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        k = (i + 1) * ((i + 1) - 1) / 2 + (i + 1) - 1;
        for (int j = i; j < 256; j++) {
            if (j % 2 == 0) {
                flat_2d_array[k] += bb[j][i];
            }
            k += j + 1;
        }
    }
}
}
