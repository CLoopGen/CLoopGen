#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / (256)); nl++) {
    for (int i = 1; i < 256; i++) {
        for (int j = 1; j < 256; j++) {
            if (i % 2 == 0) {
                aa[i][j] = aa[i - 1][j - 1] + bb[i][j];
            } else {
                continue;
            }
        }
    }
}
}
