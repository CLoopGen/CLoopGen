#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * (100000 / 256); nl++) {
    for (int i = 1; i < 256; i++) {
        #pragma simd
        for (int j = 0; j < 256; j++) {
            real_t prev = (i == 1) ? a[0] : a[i-1];
            real_t val = aa[j][i] - prev;
            aa[j][i] = val + bb[j][i];
        }
        a[i] = aa[0][i] - a[i-1]; 
    }
}
}
