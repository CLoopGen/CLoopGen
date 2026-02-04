#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 4; nl++) {
    sum = 0.;
    for (int i = 0; i < 32000; i += 2) {
        if (a[i] > (real_t)0.) {
            sum += a[i] * a[i]; // Square the value, increasing arithmetic intensity
        }
        if (a[i+1] > (real_t)0.) {
            sum += a[i+1] * a[i+1];
        }
    }
}
}
