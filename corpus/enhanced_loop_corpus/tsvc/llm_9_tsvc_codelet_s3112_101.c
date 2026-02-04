#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    sum = (real_t)0.;
    for (int i = 0; i < 16000; i++) {
        sum += a[2*i] * a[2*i+1] + (real_t)1.5;
        b[2*i] = sum;
        b[2*i+1] = sum * (real_t)0.5;
    }
}
}
