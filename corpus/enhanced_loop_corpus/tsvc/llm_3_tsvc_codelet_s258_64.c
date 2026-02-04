#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    s = 0.;
    for (int j = 0; j < 256; j += 8) { // Block-wise consecutive access, unrolled by 8
        for (int k = 0; k < 8 && (j + k) < 256; ++k) {
            int i = j + k;
            if (a[i] > 0.) {
                s = d[i] * d[i];
            }
            b[i] = s * c[i] + d[i];
            e[i] = (s + (real_t)1.) * aa[0][i];
        }
    }
}
}
