#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t dot;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 100000 * 10; nl++) {
        real_t temp_dot = 0.0;
        for (int i = 0; i < 32000; i += 8) {
            real_t s0 = a[i+0] * b[i+0];
            real_t s1 = a[i+1] * b[i+1];
            real_t s2 = a[i+2] * b[i+2];
            real_t s3 = a[i+3] * b[i+3];
            real_t s4 = a[i+4] * b[i+4];
            real_t s5 = a[i+5] * b[i+5];
            real_t s6 = a[i+6] * b[i+6];
            real_t s7 = a[i+7] * b[i+7];
            temp_dot += s0 + s1 + s2 + s3 + s4 + s5 + s6 + s7;
        }
        dot = temp_dot;
    }
}
