#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 6; nl += 2) {
    for (int i = 32000 - 1; i >= 1; i -= 2) {
        a[i] = b[i] + (real_t)1.;
        a[i-1] = b[i-1] + (real_t)1.;
    }
}
}
