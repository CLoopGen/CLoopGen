#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 10; nl++) {
    sum = (real_t)0.;
    int i = 0;
    for (; i < 32000; i += 4) {
        sum += a[i] + a[i+1] + a[i+2] + a[i+3];
    }
}
}
