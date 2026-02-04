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
            aa[j][i] = aa[j][i] + cc[j-1][i]; // Modified access: use previous element in same column (consecutive in memory for column-major would be ideal, but here we make cc access strided)
        }
        for (int j = 1; j < 256; j++) {
            bb[i][j] = bb[i][j] + cc[i-1][j]; // Similarly modified: use prior row element, creating forward dependency with strided access
        }
    }
}
}
