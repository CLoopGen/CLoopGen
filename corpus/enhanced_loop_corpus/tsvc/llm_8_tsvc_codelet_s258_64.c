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
for (int nl = 0; nl < 50000; nl++) {
    s = 0.;
    for (int i = 0; i < 256; ++i) {
        if (a[i] > 0.) {
            s += d[i] * d[i]; // Changed from assignment to accumulation
        }
        b[i] = s * c[i] + d[i] * 2.0f; // Increased arithmetic intensity
        e[i] = (s + (real_t)1.5) * aa[0][i] + c[i]; // Added extra term
    }
}
}
