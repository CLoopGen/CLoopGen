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
for (int nl = 0; nl < 200 * (100000 / 256); nl++) {
    for (int j = 1; j < 256; j++) {
        for (int i = 0; i < 256; i++) {
            int prev_j = j - 1;
            a[i] += b[i] * c[i];
            aa[j][i] = aa[prev_j][i] + bb[j][i] * a[i];
        }
    }
}
}
