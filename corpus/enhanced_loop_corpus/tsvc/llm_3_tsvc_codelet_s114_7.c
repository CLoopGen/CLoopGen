#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / (256)); nl++) {
    for (int k = 0; k < 256*256; k++) {  // Flatten 2D indices into linear traversal with indirect access
        int i = k / 256;
        int j = k % 256;
        if (j < i) {  // Maintain original condition: j < i
            aa[i][j] = aa[j][i] + bb[i][j];
        }
    }
}
}
