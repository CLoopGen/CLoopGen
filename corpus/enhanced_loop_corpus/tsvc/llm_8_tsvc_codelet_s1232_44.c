#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / 256); nl++) {
    for (int j = 0; j < 256; j++) {
        for (int i = j; i < 256; i++) {
            aa[i][j] = bb[i][j] + cc[i][j] - bb[i][j] * cc[i][j] + (bb[i][j] * bb[i][j]);
        }
    }
}
}
