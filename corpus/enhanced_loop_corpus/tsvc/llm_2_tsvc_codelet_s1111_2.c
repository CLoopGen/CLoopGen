#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int i = 0; i < 32000 / 2; i += 2) {
        a[4 * i] = c[2 * i] * b[2 * i] + d[2 * i] * b[2 * i] + c[2 * i] * c[2 * i] + d[2 * i] * b[2 * i] + d[2 * i] * c[2 * i];
        if (i + 1 < 32000 / 2) {
            a[4 * (i + 1)] = c[2 * (i + 1)] * b[2 * (i + 1)] + d[2 * (i + 1)] * b[2 * (i + 1)] + c[2 * (i + 1)] * c[2 * (i + 1)] + d[2 * (i + 1)] * b[2 * (i + 1)] + d[2 * (i + 1)] * c[2 * (i + 1)];
        }
    }
}
}
