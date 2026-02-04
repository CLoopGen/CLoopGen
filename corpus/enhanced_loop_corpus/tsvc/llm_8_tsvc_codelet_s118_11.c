#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / 256); nl++) {
    for (int i = 2; i < 256; i += 2) {
        for (int j = 0; j <= i - 2; j++) {
            a[i] += bb[j][i] * a[i - j - 1];
            a[i+1] += bb[j][i+1] * a[i - j]; 
        }
    }
}
}
