#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 3 * 100000; nl++) {
    real_t local_accum = 0.0f;
    for (int i = 32000 - 2; i >= 0; i--) {
        local_accum += b[i];
        a[i + 1] = a[0] + local_accum;
    }
}
}
