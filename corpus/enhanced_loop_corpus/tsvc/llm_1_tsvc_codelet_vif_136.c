#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int ib = 0; ib < 32000; ib += 64) {
        for (int i = ib; i < ib + 64 && i < 32000; i++) {
            if (b[i] > (real_t)0.) {
                a[i] = b[i];
            }
        }
    }
}
}
