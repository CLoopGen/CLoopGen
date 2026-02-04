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
        real_t temp_b = b[i];
        real_t temp_c = c[i];
        real_t temp_d = d[i];
        a[i] = temp_b + temp_c * temp_d;
        for (int j = 0; j < 256; j++) {
            aa[j][i] = aa[j][i] + bb[j][i] * cc[j][i];
        }
    }
}
}
