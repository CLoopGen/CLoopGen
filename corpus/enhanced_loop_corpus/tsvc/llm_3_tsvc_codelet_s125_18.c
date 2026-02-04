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
    for (int idx = 0; idx < 256 * 256; idx += 4) {
        int i0 = (idx + 0) / 256, j0 = (idx + 0) % 256;
        int i1 = (idx + 1) / 256, j1 = (idx + 1) % 256;
        int i2 = (idx + 2) / 256, j2 = (idx + 2) % 256;
        int i3 = (idx + 3) / 256, j3 = (idx + 3) % 256;
        flat_2d_array[k+0] = aa[i0][j0] + bb[i0][j0] * cc[i0][j0];
        flat_2d_array[k+1] = aa[i1][j1] + bb[i1][j1] * cc[i1][j1];
        flat_2d_array[k+2] = aa[i2][j2] + bb[i2][j2] * cc[i2][j2];
        flat_2d_array[k+3] = aa[i3][j3] + bb[i3][j3] * cc[i3][j3];
        k += 4;
    }
}
}
