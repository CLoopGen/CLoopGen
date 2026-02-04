#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t x;
extern real_t y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    x = b[31999];
    y = b[31998];
    for (int i = 0; i < 32000; i += 2) {
        a[i] = (b[i] + x + y + b[(i+1) % 32000]) * (real_t)0.25;
        if (i + 1 < 32000) {
            a[i+1] = (b[i+1] + x + b[i] + b[(i+2) % 32000]) * (real_t)0.25;
        }
        y = x;
        x = b[i];
    }
}
}
