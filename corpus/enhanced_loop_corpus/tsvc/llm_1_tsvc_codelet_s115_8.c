#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 1000 * (100000 / 256); nl++) {
    for (int j = 0; j < 256; j++) {
        for (int k = 0; k < (256 - j - 1); k++) {
            int i = j + 1 + k;
            a[i] -= aa[j][i] * a[j];
        }
    }
}
}
