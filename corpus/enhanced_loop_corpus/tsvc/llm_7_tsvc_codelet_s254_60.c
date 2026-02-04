#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    real_t prev_b = b[31999];
    for (int i = 0; i < 32000; i += 4) {
        a[i]   = (b[i]   + prev_b) * (real_t)0.5;
        if (i + 1 < 32000) a[i+1] = (b[i+1] + b[i]) * (real_t)0.5;
        if (i + 2 < 32000) a[i+2] = (b[i+2] + b[i+1]) * (real_t)0.5;
        if (i + 3 < 32000) a[i+3] = (b[i+3] + b[i+2]) * (real_t)0.5;
        prev_b = (i + 3 < 32000) ? b[i+2] : ((i + 2 < 32000) ? b[i+1] : ((i + 1 < 32000) ? b[i] : b[31999]));
    }
}
}
