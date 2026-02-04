#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 4 * 100000; nl++) {
        for (int i = 0; i < 32000; i += 4) {
            x = b[i] * c[i] + a[i] * d[i] + e[i];
            a[i] = x - (real_t)1.;
            b[i] = x;
            if (i + 1 < 32000) {
                x = b[i+1] * c[i+1] + a[i+1] * d[i+1] + e[i+1];
                a[i+1] = x - (real_t)1.;
                b[i+1] = x;
            }
            if (i + 2 < 32000) {
                x = b[i+2] * c[i+2] + a[i+2] * d[i+2] + e[i+2];
                a[i+2] = x - (real_t)1.;
                b[i+2] = x;
            }
            if (i + 3 < 32000) {
                x = b[i+3] * c[i+3] + a[i+3] * d[i+3] + e[i+3];
                a[i+3] = x - (real_t)1.;
                b[i+3] = x;
            }
        }
    }
}
