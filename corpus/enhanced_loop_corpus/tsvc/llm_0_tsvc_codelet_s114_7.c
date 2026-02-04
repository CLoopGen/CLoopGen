#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / (256)); nl++) {
    for (int i = 0; i < 256; i++) {
        for (int k = 0; k < i; k++) {
            for (int j = 0; j < 1; j++) {
                aa[i][k] = aa[k][i] + bb[i][k];
            }
        }
    }
}
}
