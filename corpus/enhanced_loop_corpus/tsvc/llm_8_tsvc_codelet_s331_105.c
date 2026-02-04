#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern int j;
extern real_t chksum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    j = -1;
    real_t sum = 0.0f;
    for (int i = 0; i < 32000; i += 2) {
        if (a[i] < (real_t)0.) {
            j = i;
        }
        sum += a[i] * a[i] + (real_t)i * 0.5f;
    }
    chksum = (real_t)j + sum * 1e-5f;
}
}
