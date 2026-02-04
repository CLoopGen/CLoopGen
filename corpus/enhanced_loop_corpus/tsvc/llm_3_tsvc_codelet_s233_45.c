#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / 256); nl++) {
    for (int i = 1; i < 256; i += 2) {  // Strided iteration with step 2
        for (int j = 1; j < 256; j += 2) {
            aa[j][i] = aa[j-1][i] + cc[j][i];
            if (i + 1 < 256 && j + 1 < 256) {
                aa[j+1][i+1] = aa[j][i+1] + cc[j+1][i+1];  // Strided and offset write
            }
        }
        for (int j = 1; j < 256; j += 2) {
            bb[j][i] = bb[j][i-1] + cc[j][i];
            if (i + 1 < 256 && j + 1 < 256) {
                bb[j+1][i+1] = bb[j+1][i] + cc[j+1][i+1];
            }
        }
    }
}
}
