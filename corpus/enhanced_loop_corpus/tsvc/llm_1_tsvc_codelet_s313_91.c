#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t dot;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    dot = (real_t)0.;
    for (int nl = 0; nl < 100000 * 5; nl++) {
        for (int i = 0; i < 32000; i += 8) {
            dot += a[i+0] * b[i+0];
            dot += a[i+1] * b[i+1];
            dot += a[i+2] * b[i+2];
            dot += a[i+3] * b[i+3];
            dot += a[i+4] * b[i+4];
            dot += a[i+5] * b[i+5];
            dot += a[i+6] * b[i+6];
            dot += a[i+7] * b[i+7];
        }
    }
}
