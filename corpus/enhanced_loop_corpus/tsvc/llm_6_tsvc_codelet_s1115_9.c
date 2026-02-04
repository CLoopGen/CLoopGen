#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        real_t temp[256];
        for (int j = 0; j < 256; j++) {
            temp[j] = cc[j][i]; // Preload with anti-dependence (WAR) broken via local copy
        }
        for (int j = 0; j < 256; j++) {
            aa[i][j] = aa[i][j] * temp[j] + bb[i][j]; // Eliminates WAR dependency on cc[j][i]
        }
    }
}
}
