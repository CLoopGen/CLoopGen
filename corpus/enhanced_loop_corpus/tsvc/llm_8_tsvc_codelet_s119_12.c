#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 400 * (100000 / (256)); nl++) {
    for (int i = 2; i < 256; i++) {
        for (int j = 2; j < 256; j++) {
            aa[i][j] = aa[i - 1][j - 1] + aa[i - 2][j] + bb[i][j] + bb[i][j-1];
        }
    }
}
}
