#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    k = 0;
    for (int i = 0; i < 256 * 256; i++) {
        int row = i / 256;
        int col = i % 256;
        flat_2d_array[k] = aa[row][col] + bb[row][col] * cc[row][col];
        k++;
    }
}
}
