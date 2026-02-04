#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 20 * (100000 / 256); nl++) {
    for (int i = 1; i < 256; i++) {
        real_t temp_sum = 0.0f;
        for (int j = 0; j < 256; j++) {
            temp_sum += aa[j][i] * bb[j][i]; // Increased arithmetic intensity with multiply
        }
        a[i] = temp_sum - a[i - 1];
        for (int j = 0; j < 256; j++) {
            aa[j][i] = a[i] + bb[j][i]; // Simplified update after reduction
        }
    }
}
}
