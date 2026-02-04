#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t x;
extern real_t y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    x = b[32000 - 1];
    y = b[32000 - 2];
    for (int i = 0; i < 32000; i += 2) {
        a[i] = (b[i] + x + y) * (real_t)0.33300000000000002;
        if (i + 1 < 32000) {
            a[i + 1] = (b[i + 1] + x + y) * (real_t)0.33300000000000002;
        }
        y = x;
        x = b[i];
    }
}
}
