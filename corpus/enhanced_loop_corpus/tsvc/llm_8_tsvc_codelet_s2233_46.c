#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50 * (100000 / 256); nl++) {
    for (int i = 2; i < 256; i++) {
        for (int j = 2; j < 256; j++) {
            aa[j][i] = aa[j-2][i] + cc[j][i] * 2.0f;
            aa[j][i] += aa[j-1][i] - cc[j-1][i];
        }
        for (int j = 2; j < 256; j++) {
            bb[i][j] = bb[i-2][j] + cc[i][j] * 2.0f;
            bb[i][j] += bb[i-1][j] - cc[i-1][j];
        }
    }
}
}
