#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    #pragma unroll(8)
    for (int i = 0; i < 32000; i += 4) {
        // Eliminate write-after-write (WAW) and write-after-read (WAR) hazards by using temporaries
        real_t prod0 = b[i] > 0.0 ? b[i] * c[i] : 0.0;
        real_t prod1 = b[i+1] > 0.0 ? b[i+1] * c[i+1] : 0.0;
        real_t prod2 = b[i+2] > 0.0 ? b[i+2] * c[i+2] : 0.0;
        real_t prod3 = b[i+3] > 0.0 ? b[i+3] * c[i+3] : 0.0;

        a[i]   += prod0;
        a[i+1] += prod1;
        a[i+2] += prod2;
        a[i+3] += prod3;
    }
}
}
