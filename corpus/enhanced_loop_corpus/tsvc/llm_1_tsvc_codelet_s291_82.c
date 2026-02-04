#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int im1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    im1 = 32000 - 1;
    int i = 0;
    for (; i < 8000; i++) {
        a[i] = (b[i] + b[im1]) * (real_t)0.5;
        im1 = i;
    }
    for (; i < 16000; i++) {
        a[i] = (b[i] + b[im1]) * (real_t)0.5;
        im1 = i;
    }
    for (; i < 24000; i++) {
        a[i] = (b[i] + b[im1]) * (real_t)0.5;
        im1 = i;
    }
    for (; i < 32000; i++) {
        a[i] = (b[i] + b[im1]) * (real_t)0.5;
        im1 = i;
    }
}
}
