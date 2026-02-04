#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 5) {
        real_t temp0 = alpha * b[i];
        real_t temp1 = alpha * b[i + 1];
        real_t temp2 = alpha * b[i + 2];
        real_t temp3 = alpha * b[i + 3];
        real_t temp4 = alpha * b[i + 4];
        a[i] += temp0;
        a[i + 1] += temp1;
        a[i + 2] += temp2;
        a[i + 3] += temp3;
        a[i + 4] += temp4;
        a[i] += temp0;
        a[i + 1] += temp1;
        a[i + 2] += temp2;
        a[i + 3] += temp3;
        a[i + 4] += temp4;
    }
}
}
