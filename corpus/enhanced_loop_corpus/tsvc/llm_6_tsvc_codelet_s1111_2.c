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
    real_t temp_c, temp_d;
    for (int i = 0; i < 32000 / 2; i++) {
        temp_c = c[i];
        temp_d = d[i];
        a[2 * i] = temp_c * b[i] + temp_d * b[i] + temp_c * temp_c + temp_d * b[i] + temp_d * temp_c;
    }
}
}
