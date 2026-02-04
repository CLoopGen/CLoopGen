#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 1 * 100000; nl++) {
    sum = 0.;
    for (int i = 0; i < 16000; i++) {
        real_t temp1 = c[2*i] + d[2*i];
        real_t temp2 = c[2*i+1] + d[2*i+1];
        a[2*i] = temp1;
        a[2*i+1] = temp2;
        sum += temp1 + temp2;

        real_t temp3 = c[2*i] + e[2*i];
        real_t temp4 = c[2*i+1] + e[2*i+1];
        b[2*i] = temp3;
        b[2*i+1] = temp4;
        sum += temp3 + temp4;
    }
}
}
