#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    real_t prev_a = a[0];
    for (int i = 0; i < 32000 - 1; i++) {
        real_t curr_a = b[i] * c[i] * d[i];
        a[i] = curr_a;
        b[i] = prev_a * curr_a * d[i];
        prev_a = curr_a;
    }
}
}
