#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int im1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 2 * 100000; nl++) {
        for (int i = 0; i < 32000; i++) {
            int prev_i = (i == 0) ? 31999 : i - 1;
            a[i] = (b[i] + b[prev_i]) * (real_t)0.5;
        }
    }
}
