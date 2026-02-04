#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int im1;
extern int im2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    im1 = 32000 - 1;
    im2 = 32000 - 2;
    for (int ib = 0; ib < 32000; ib += 32) {
        for (int i = ib; i < ib + 32 && i < 32000; i++) {
            a[i] = (b[i] + b[im1] + b[im2]) * (real_t)0.33300000000000002;
            im2 = im1;
            im1 = i;
        }
    }
}
}
