#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 400 * (100000 / 256); nl++) {
    for (int i = 1; i < 128; i++) {
        real_t temp1 = 0.0f, temp2 = 0.0f;
        for (int j = 0; j < i; j++) {
            temp1 += bb[j][i] * a[i - j - 1];
            temp2 += bb[j][i + 128] * a[255 - j];
        }
        a[i] += temp1;
        a[i + 128] += temp2;
    }
}
}
