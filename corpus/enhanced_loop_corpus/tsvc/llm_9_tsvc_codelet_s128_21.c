#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl += 2) {
    j = -1;
    for (int i = 0; i < 32000 / 8; i++) {
        k = j + 1;
        a[i] = b[k] - d[i];
        j = k + 1;
        b[k] = a[i] + c[k];
        c[k] = c[k] * a[i] - b[k] + d[i];
        a[i + 4000] = d[i] + c[k] * b[k];
        j = j + 1;
    }
}
}
