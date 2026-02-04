#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 400 * (100000 / 256); nl += 2) {
    for (int i = 0; i < 128; i++) {
        real_t temp1 = b[i] * c[i];
        real_t temp2 = b[i + 128] * c[i + 128];
        a[i] += temp1;
        a[i + 128] += temp2;
        for (int j = 1; j < 128; j++) {
            aa[j][i] = aa[j - 1][i] + bb[j][i] * a[i];
            aa[j][i + 128] = aa[j - 1][i + 128] + bb[j][i + 128] * a[i + 128];
        }
    }
}
}
