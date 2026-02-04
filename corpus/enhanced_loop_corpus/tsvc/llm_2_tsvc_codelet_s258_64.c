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
    for (int i = 0; i < 256; ++i) {
        int idx = i * 4; // Strided access with stride 4
        if (idx < 256 && a[idx] > 0.) {
            s = d[idx] * d[idx];
        }
        if (idx < 256) {
            b[idx] = s * c[idx] + d[idx];
            e[idx] = (s + (real_t)1.) * aa[0][idx];
        }
    }
}
}
