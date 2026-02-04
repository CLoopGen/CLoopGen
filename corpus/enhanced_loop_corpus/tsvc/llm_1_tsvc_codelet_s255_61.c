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
        x = b[31999];
        y = b[31998];
        for (int ib = 0; ib < 32000; ib += 16) {
            int upper = (ib + 16 < 32000) ? ib + 16 : 32000;
            for (int i = ib; i < upper; i++) {
                a[i] = (b[i] + x + y) * (real_t)0.33300000000000002;
                y = x;
                x = b[i];
            }
        }
    }
}
