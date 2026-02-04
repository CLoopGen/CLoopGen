#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        for (int j = 1; j < 256; j++) {
            if (j % 2 == 0) {
                a[j] = (real_t)1. - a[j - 1];
                aa[j][i] = a[j] + bb[j][i] * d[j];
            } else {
                continue;
            }
        }
    }
}
}
