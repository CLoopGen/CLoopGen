#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 500 * (100000 / 256); nl++) {
    for (int j = 0; j < 256; j += 2) {
        for (int i = j + 1; i < 256; i++) {
            a[i] -= aa[j][i] * a[j];
            if (j + 1 < 256 && i > j + 1) {
                a[i] -= aa[j+1][i] * a[j+1];
            }
        }
    }
}
}
