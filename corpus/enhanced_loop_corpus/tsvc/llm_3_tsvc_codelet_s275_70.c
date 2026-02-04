#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * (100000 / 256); nl++) {
    for (int stride = 1; stride <= 256; stride *= 2) {
        for (int i = 0; i < 256; i += stride) {
            if (i < 256 && aa[0][i] > (real_t)0.) {
                for (int j = 1; j < 256; j++) {
                    int prev = (j - 1) & (255);
                    aa[j][i] = aa[prev][i] + bb[j][i] * cc[j][i];
                }
            }
        }
    }
}
}
