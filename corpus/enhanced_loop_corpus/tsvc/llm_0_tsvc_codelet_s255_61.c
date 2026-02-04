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
        for (int i = 0; i < 32000; i += 2) {
            a[i] = (b[i] + x + y) * (real_t)0.33300000000000002;
            if (i + 1 < 32000) {
                a[i + 1] = (b[i + 1] + x + y) * (real_t)0.33300000000000002;
            }
            real_t temp_x = b[i];
            real_t temp_y = (i == 0) ? y : x;
            y = temp_x;
            x = b[i];
            if (i + 1 < 32000) {
                y = x;
                x = b[i + 1];
            }
        }
    }
}
