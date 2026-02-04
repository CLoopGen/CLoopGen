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
        for (int k = 0; k < 255; k++) {
            int j = (k + i) & 254; // Indirect and non-sequential access pattern using stride and offset
            if (j >= 1 && j < 256) {
                aa[j][i] = aa[j-1][i] + cc[j][i];
            }
        }
        for (int k = 0; k < 255; k++) {
            int j = 255 - ((k + i) & 254); // Reverse indirect indexing
            if (j >= 1 && j < 256) {
                bb[i][j] = bb[i-1][j] + cc[i][j];
            }
        }
    }
}
}
