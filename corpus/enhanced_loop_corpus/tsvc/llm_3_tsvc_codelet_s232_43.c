#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    for (int j = 1; j < 256; j++) {
        for (int i = 1; i <= j; i += 2) {
            int i1 = i;
            int i2 = i + 1;
            if (i1 <= j) {
                aa[j][i1] = aa[j][i1 - 1] * aa[j][i1 - 1] + bb[j][i1];
            }
            if (i2 <= j) {
                aa[j][i2] = aa[j][i2 - 1] * aa[j][i2 - 1] + bb[j][i2];
            }
        }
    }
}
}
