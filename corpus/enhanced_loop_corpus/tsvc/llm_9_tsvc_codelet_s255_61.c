#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t x;
extern real_t y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    x = b[0];
    y = b[1];
    for (int i = 2; i < 32000; i++) {
        real_t temp1 = b[i] + x;
        real_t temp2 = temp1 + y;
        real_t factor = (real_t)0.33300000000000002;
        a[i] = temp2 * factor;
        a[i] += (x - y) * (real_t)0.1;
        y = x;
        x = b[i];
    }
}
}
