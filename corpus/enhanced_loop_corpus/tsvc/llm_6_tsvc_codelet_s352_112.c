#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t dot;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    real_t dot0 = (real_t)0.;
    real_t dot1 = (real_t)0.;
    real_t dot2 = (real_t)0.;
    real_t dot3 = (real_t)0.;
    real_t dot4 = (real_t)0.;
    for (int i = 0; i < 32000; i += 5) {
        dot0 = dot0 + a[i] * b[i];
        dot1 = dot1 + a[i + 1] * b[i + 1];
        dot2 = dot2 + a[i + 2] * b[i + 2];
        dot3 = dot3 + a[i + 3] * b[i + 3];
        dot4 = dot4 + a[i + 4] * b[i + 4];
    }
    dot = dot0 + dot1 + dot2 + dot3 + dot4;
}
}
