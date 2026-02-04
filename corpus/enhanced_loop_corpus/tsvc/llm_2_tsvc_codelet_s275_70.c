#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        if (aa[i][0] > (real_t)0.) {
            for (int j = 1; j < 256; j++) {
                aa[i][j] = aa[i][j - 1] + bb[i][j] * cc[i][j];
            }
        }
    }
}
}
