#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50 * (100000 / 256); nl++) {
    for (int j = 0; j < 256; j += 2) {
        for (int i = j; i < 256; i++) {
            aa[i][j] = bb[i][j] + cc[i][j];
            if (j + 1 < 256) {
                aa[i][j+1] = bb[i][j+1] + cc[i][j+1];
            }
        }
    }
}
}
