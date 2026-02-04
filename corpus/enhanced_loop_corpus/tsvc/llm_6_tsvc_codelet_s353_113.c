#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;
extern real_t alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    real_t temp0, temp1, temp2, temp3, temp4;
    for (int i = 0; i < 32000; i += 5) {
        temp0 = alpha * b[ip[i]];
        temp1 = alpha * b[ip[i + 1]];
        temp2 = alpha * b[ip[i + 2]];
        temp3 = alpha * b[ip[i + 3]];
        temp4 = alpha * b[ip[i + 4]];
        a[i] += temp0;
        a[i + 1] += temp1;
        a[i + 2] += temp2;
        a[i + 3] += temp3;
        a[i + 4] += temp4;
    }
}
}
