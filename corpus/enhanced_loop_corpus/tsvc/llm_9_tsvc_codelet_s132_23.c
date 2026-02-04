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
for (int nl = 0; nl < 200 * 100000; nl += 2) {
    for (int i = 1; i < 128; i++) {
        real_t temp1 = aa[k][i - 1] + b[i] * c[1];
        real_t temp2 = aa[k][i]     + b[i + 128] * c[1];
        aa[j][i] = temp1;
        aa[j][i + 128] = temp2;
    }
}
}
