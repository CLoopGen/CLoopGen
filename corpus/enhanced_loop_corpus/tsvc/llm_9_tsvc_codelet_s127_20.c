#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 1 * 100000; nl++) {
    j = 0;
    for (int i = 0; i < 32000 / 8; i += 2) {
        a[j] = b[i] + c[i] * d[i];
        a[j + 1] = b[i + 1] + d[i + 1] * e[i + 1];
        a[j + 2] = b[i + 2] + c[i + 2] * d[i + 2];
        j += 3;
    }
}
}
