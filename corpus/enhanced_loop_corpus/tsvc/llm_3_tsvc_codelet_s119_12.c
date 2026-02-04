#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / (256)); nl++) {
    for (int stride = 1; stride < 256; stride *= 2) {
        for (int i = 1; i + stride < 256; i += stride) {
            for (int j = 1; j < 256; j++) {
                aa[i + stride][j] = aa[i + stride - 1][j - 1] + bb[i + stride][j];
            }
        }
    }
}
}
