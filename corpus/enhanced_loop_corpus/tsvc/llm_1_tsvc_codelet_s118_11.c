#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / 256); nl++) {
    for (int k = 1; k < 256 * 256; k++) {
        int i = k / 256;
        int j = k % 256;
        if (j < i && i < 256) {
            a[i] += bb[j][i] * a[i - j - 1];
        }
    }
}
}
