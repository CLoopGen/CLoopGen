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
    real_t temp[255];
    for (int i = 1; i < 256; i++) {
        temp[i-1] = aa[k][i - 1] + b[i] * c[1];
    }
    for (int i = 1; i < 256; i++) {
        aa[j][i] = temp[i-1];
    }
}
}
