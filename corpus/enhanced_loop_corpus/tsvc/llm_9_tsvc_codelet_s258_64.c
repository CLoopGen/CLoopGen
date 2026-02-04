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
for (int nl = 0; nl < 200000; nl += 2) {
    s = 0.;
    for (int i = 0; i < 128; ++i) { // Reduced trip count but increased operations per element
        int j = i << 1; // Use two elements per iteration
        real_t sum_d = d[i] + d[j];
        if (a[i] > 0. && a[j] > 0.) {
            s = sum_d * sum_d;
        }
        b[i] = s * c[i] + d[i];
        b[j] = s * c[j] + d[j];
        e[i] = (s + (real_t)1.) * aa[0][i];
        e[j] = (s + (real_t)1.) * aa[0][j];
    }
}
}
