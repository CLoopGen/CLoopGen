#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 400 * 100000; nl++) {
    for (int i = 1; i < 256; i++) {
        aa[j][i] = aa[k][i] + b[i] * c[i];
    }
    j = (j + 1) % 256;
    k = (k + 1) % 256;
}
}
