#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    for (int i = 0; i < 16000; i++) {
        real_t sum = (b[i] + b[31999 - i]) * (real_t)0.5;
        if (sum > (real_t)0.) {
            a[i] = sum;
            a[31999 - i] = sum;
        }
    }
}
}
