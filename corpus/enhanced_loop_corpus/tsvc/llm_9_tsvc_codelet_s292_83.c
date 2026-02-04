#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int im1;
extern int im2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl += 2) {
    im1 = 32000 - 1;
    im2 = 32000 - 2;
    for (int i = 0; i < 16000; i++) {
        int j = 2 * i;
        a[j] = (b[j] + b[im1] + b[im2]) * (real_t)0.33300000000000002;
        if (j + 1 < 32000) {
            a[j+1] = (b[j+1] + b[im1] + b[im2]) * (real_t)0.33300000000000002;
        }
        im2 = im1;
        im1 = j;
    }
}
}
