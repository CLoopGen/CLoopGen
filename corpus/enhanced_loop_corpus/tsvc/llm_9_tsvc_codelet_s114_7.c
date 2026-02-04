#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    for (int i = 0; i < 256; i += 2) {
        for (int j = 0; j < i; j += 2) {
            real_t temp = aa[j][i] + bb[i][j];
            aa[i][j] = temp * temp;
        }
    }
}
}
