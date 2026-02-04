#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    sum = 0.;
    for (int i = 0; i < 32000; i++) {
        sum += (a[i] > (real_t)0.) ? a[i] : 0.;
    }
}
}
