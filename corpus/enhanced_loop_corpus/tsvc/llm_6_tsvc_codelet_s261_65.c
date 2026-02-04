#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern real_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    t = a[1] + b[1];
    a[1] = t + c[0];
    t = c[1] * d[1];
    c[1] = t;
    for (int i = 2; i < 32000; ++i) {
        real_t temp_t1 = a[i] + b[i];
        a[i] = temp_t1 + c[i - 1];
        real_t temp_t2 = c[i] * d[i];
        c[i] = temp_t2;
    }
}
}
