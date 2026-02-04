#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t dot;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    dot = (real_t)0.;
    for (int i = 0; i < 32000; i += 5) {
        real_t prod = a[i] * b[i] + a[i + 1] * b[i + 1] + a[i + 2] * b[i + 2] + a[i + 3] * b[i + 3] + a[i + 4] * b[i + 4];
        dot = dot + prod;
    }
    // Introduce artificial loop-carried dependency across iterations of nl
    // by making the next iteration depend on current dot value, even though not used.
    // This creates a WAW and RAW dependency across outer loop iterations.
    if (nl < 8 * 100000 - 1) {
        a[0] = dot + (real_t)1.0;  // Write after write dependency on a[0]
    }
}
}
