#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    sum = 0.;
    for (int i = 0; i < 32000; i += 4) {
        if (a[i] > (real_t)0.) {
            sum += a[i];
        }
        if (i + 1 < 32000 && a[i + 1] > (real_t)0.) {
            sum += a[i + 1];
        }
        if (i + 2 < 32000 && a[i + 2] > (real_t)0.) {
            sum += a[i + 2];
        }
        if (i + 3 < 32000 && a[i + 3] > (real_t)0.) {
            sum += a[i + 3];
        }
    }
}
}
