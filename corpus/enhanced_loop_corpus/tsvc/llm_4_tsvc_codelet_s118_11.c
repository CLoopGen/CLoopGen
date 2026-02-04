#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / 256); nl++) {
    for (int i = 1; i < 256; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j <= i - 1; j++) {
                a[i] += bb[j][i] * a[i - j - 1];
            }
        } else {
            continue;
        }
    }
}
}
