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
        int base_idx = i * 256;
        for (int j = i; j < 256; j++) {
            flat_2d_array[base_idx + j] += bb[j][i];
        }
    }
}
}
