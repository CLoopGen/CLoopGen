#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 5 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        if (aa[0][i] > (real_t)0.) {
            for (int j = 1; j < 256; j++) {
                real_t temp1 = bb[j][i] * cc[j][i];
                real_t temp2 = bb[j][i] + cc[j][i];
                aa[j][i] = aa[j - 1][i] + temp1 * temp2;
            }
        }
    }
}
}
