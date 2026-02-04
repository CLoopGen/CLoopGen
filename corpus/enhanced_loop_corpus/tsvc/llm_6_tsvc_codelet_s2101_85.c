#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * 100000; nl++) {
    real_t temp[256];
    for (int i = 0; i < 256; i++) {
        temp[i] = bb[i][i] * cc[i][i];
    }
    for (int i = 0; i < 256; i++) {
        aa[i][i] += temp[i];
    }
}
}
