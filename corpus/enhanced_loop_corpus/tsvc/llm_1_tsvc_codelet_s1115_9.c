#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        aa[i][0] = aa[i][0] * cc[0][i] + bb[i][0];
        for (int j = 1; j < 256; j++) {
            aa[i][j] = aa[i][j] * cc[j][i] + bb[i][j];
            aa[i][j-1] = aa[i][j-1] * cc[j-1][i] + bb[i][j-1];
        }
    }
}
}
