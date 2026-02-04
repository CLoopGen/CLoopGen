#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
extern int *restrict ip;
extern int j;
extern int inc;
extern real_t sum;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * 100000; nl++) {
    real_t local_sum = 0.0;
    for (int i = 0; i < 256 - 1; i++) {
        int off_local = inc + i;
        local_sum += a[off_local] * aa[j - 1][ip[i]];
    }
    sum = local_sum;
}
}
