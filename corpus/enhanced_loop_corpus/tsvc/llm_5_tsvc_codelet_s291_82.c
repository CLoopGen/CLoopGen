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
    for (int i = 0; i < 32000; i++) {
        if (i % 2 == 0) {
            a[i] = (b[i] + b[im1]) * (real_t)0.5;
        } else {
            a[i] = b[i];
        }
        im1 = i;
    }
}
}
