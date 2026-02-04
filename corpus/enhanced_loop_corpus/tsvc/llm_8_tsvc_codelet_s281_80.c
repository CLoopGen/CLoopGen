#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    for (int i = 0; i < 32000; i += 2) {
        real_t temp1 = a[32000 - i - 1] + b[i] * c[i];
        a[i] = temp1 - (real_t)1.;
        b[i] = temp1;
        if (i + 1 < 32000) {
            real_t temp2 = a[32000 - i - 2] + b[i + 1] * c[i + 1];
            a[i + 1] = temp2 - (real_t)1.;
            b[i + 1] = temp2;
        }
    }
}
}
