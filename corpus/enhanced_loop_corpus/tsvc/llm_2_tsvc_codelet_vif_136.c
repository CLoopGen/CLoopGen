#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000; i += 4) {
        if (b[i] > (real_t)0.) {
            a[i] = b[i];
        }
        if (b[i+1] > (real_t)0. && (i+1) < 32000) {
            a[i+1] = b[i+1];
        }
        if (b[i+2] > (real_t)0. && (i+2) < 32000) {
            a[i+2] = b[i+2];
        }
        if (b[i+3] > (real_t)0. && (i+3) < 32000) {
            a[i+3] = b[i+3];
        }
    }
}
}
