#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 4) {
        a[i] += b[i] * c[i];
        a[i+1] += b[i+1] * c[i+1];
        a[i+2] += b[i+2] * c[i+2];
        a[i+3] += b[i+3] * c[i+3];
    }
}
}
