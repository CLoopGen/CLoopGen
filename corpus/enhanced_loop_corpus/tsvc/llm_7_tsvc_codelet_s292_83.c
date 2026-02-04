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
    for (int i = 1; i < 31999; i++) {
        a[i] = (b[i] + b[i-1] + b[i+1]) * (real_t)0.33300000000000002;
    }
    // Handle boundary elements without loop-carried dependencies
    a[0] = (b[0] + b[31999] + b[31998]) * (real_t)0.33300000000000002;
    a[31999] = (b[31999] + b[31998] + b[31997]) * (real_t)0.33300000000000002;
}
}
