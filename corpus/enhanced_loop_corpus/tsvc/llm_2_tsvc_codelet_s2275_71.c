#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j += 2) {
            if (j + 1 < 256) {
                aa[j][i] = aa[j][i] + bb[j][i] * cc[j][i];
                aa[j+1][i] = aa[j+1][i] + bb[j+1][i] * cc[j+1][i];
            } else {
                aa[j][i] = aa[j][i] + bb[j][i] * cc[j][i];
            }
        }
        a[i] = b[i] + c[i] * d[i];
    }
}
}
