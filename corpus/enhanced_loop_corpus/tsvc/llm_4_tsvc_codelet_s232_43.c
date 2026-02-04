#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    for (int j = 1; j < 256; j++) {
        for (int i = 1; i <= j; i++) {
            if (aa[j][i - 1] > 0.0f) {
                aa[j][i] = aa[j][i - 1] * aa[j][i - 1] + bb[j][i];
            } else {
                aa[j][i] = bb[j][i]; // Avoid squaring negative values; use bb directly
            }
        }
    }
}
}
