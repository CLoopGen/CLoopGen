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
    for (int i = 1; i < 32000 - 1; i += 2) {
        a[i] = b[i - 1] + c[i] * d[i];
        b[i] = b[i + 1] - e[i] * d[i];
        if (i + 1 < 32000 - 1) {
            a[i + 1] = b[i] + c[i + 1] * d[i + 1];
            b[i + 1] = b[i + 2] - e[i + 1] * d[i + 1];
        }
    }
}
}
