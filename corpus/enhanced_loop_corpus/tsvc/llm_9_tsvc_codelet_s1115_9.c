#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            real_t temp1 = aa[i][j] * cc[j][i];
            real_t temp2 = bb[i][j] * cc[j][i];
            aa[i][j] = temp1 + temp2 - temp1 * temp2 * 0.001f;
        }
    }
}
}
