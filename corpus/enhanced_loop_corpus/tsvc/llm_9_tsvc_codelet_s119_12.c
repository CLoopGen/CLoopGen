#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    for (int i = 1; i < 128; i += 2) {
        for (int j = 1; j < 128; j += 2) {
            real_t temp1 = aa[i-1][j-1] + bb[i][j];
            real_t temp2 = aa[i][j-1] + bb[i-1][j];
            aa[i][j] = temp1;
            if (i+1 < 128 && j+1 < 128) {
                aa[i+1][j+1] = temp2;
            }
        }
    }
}
}
