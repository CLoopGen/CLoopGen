#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    real_t temp_a;
    for (int i = 0; i < 32000; i++) {
        temp_a = a[32000 - i - 1] + b[i] * c[i];
        a[i] = temp_a - (real_t)1.;
        b[i] = temp_a;
    }
}
}
