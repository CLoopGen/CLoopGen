#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    for (int j = 1; j < 256; j++) {
        aa[j][1] = aa[j][0] * aa[j][0] + bb[j][1];
        for (int i = 2; i <= j; i++) {
            aa[j][i] = aa[j][i - 1] * aa[j][i - 1] + bb[j][i];
        }
    }
}
}
