#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 3; nl++) {
    #pragma unroll(8)
    for (int i = 0; i < 32000; i += 8) {
        a[i]     = b[i]     + (real_t)1.;
        a[i+1]   = b[i+1]   + (real_t)1.;
        a[i+2]   = b[i+2]   + (real_t)1.;
        a[i+3]   = b[i+3]   + (real_t)1.;
        a[i+4]   = b[i+4]   + (real_t)1.;
        a[i+5]   = b[i+5]   + (real_t)1.;
        a[i+6]   = b[i+6]   + (real_t)1.;
        a[i+7]   = b[i+7]   + (real_t)1.;
    }
}
}
