#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t bb[256][256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / 256); nl++) {
    for (int j = 0; j < 256; j++) {
        for (int i = 0; i <= j; i++) {
            int k = (i + 1) * (i) / 2 + i;
            k += j;
            flat_2d_array[k] += bb[j][i];
        }
    }
}
}
