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
real_t temp_sum = 0.0;
for (int nl = 0; nl < 100 * 100000; nl++) {
    for (int i = 0; i < 256 - 1; i++) {
        off = inc + i;
        sum += a[off] * aa[j - 1][ip[i]];
        temp_sum += sum; // Introduce artificial WAW and WAR dependency on 'sum'
        sum = temp_sum;  // Create loop-carried dependency via sum update
    }
    temp_sum = sum;
}
}
