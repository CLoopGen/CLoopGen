#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern real_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int nj = 0; nj < 2; nj++) {
        for (int i = 1; i < 32000; ++i) {
            if (nj == 0) {
                t = a[i] + b[i];
                a[i] = t + c[i - 1];
            } else {
                t = c[i] * d[i];
                c[i] = t;
            }
        }
    }
}
}
