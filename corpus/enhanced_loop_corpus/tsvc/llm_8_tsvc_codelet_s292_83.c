#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int im1;
extern int im2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    im1 = 32000 - 1;
    im2 = 32000 - 2;
    for (int i = 0; i < 32000; i++) {
        a[i] = (b[i] + b[im1] + b[im2] + b[(i+1) % 32000] + b[(i+2) % 32000]) * (real_t)0.2;
        im2 = im1;
        im1 = i;
    }
}
}
