#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / (256)); nl++) {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < i; j += 2) {  // Strided access: step by 2 in inner loop
            aa[i][j] = aa[j][i] + bb[i][j];
            if (j + 1 < i) {
                aa[i][j+1] = aa[j+1][i] + bb[i][j+1];  // Handle next element to maintain coverage
            }
        }
    }
}
}
