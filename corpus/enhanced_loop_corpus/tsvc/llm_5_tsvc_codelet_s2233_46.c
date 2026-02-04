#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / 256); nl++) {
    for (int i = 1; i < 256; i++) {
        for (int j = 1; j < 256; j++) {
            if (j < 128) {
                aa[j][i] = aa[j - 1][i] + cc[j][i];
            } else {
                aa[j][i] = cc[j][i]; // Different path: skip dependency on aa[j-1][i]
            }
        }
        for (int j = 1; j < 256; j++) {
            if (j % 4 == 0) {
                bb[i][j] = bb[i - 1][j] + cc[i][j];
            } else {
                bb[i][j] = bb[i][j]; // Self-assignment to maintain write, no data change
            }
        }
    }
}
}
