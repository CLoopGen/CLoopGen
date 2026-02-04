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
    for (int i = 0; i < 8000; i++) {
        int indices[4] = {i, i + 8000, i + 16000, i + 24000};
        for (int j = 0; j < 4; j++) {
            int idx = indices[j];
            if (idx < 32000 && a[idx] < (real_t)0.) {
                if (b[idx] > a[idx]) {
                    c[idx] += d[idx] * e[idx];
                }
            }
        }
    }
}
}
