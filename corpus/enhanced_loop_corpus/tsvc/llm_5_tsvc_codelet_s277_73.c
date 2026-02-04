#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000 - 1; i++) {
        int skip_a_update = 0;
        if (a[i] >= (real_t)0.) {
            // Skip to setting b[i+1] directly
        } else if (b[i] >= (real_t)0.) {
            // Proceed to update b[i+1] without updating a[i]
        } else {
            a[i] += c[i] * d[i];
        }
        b[i + 1] = c[i] + d[i] * e[i];
    }
}
}
