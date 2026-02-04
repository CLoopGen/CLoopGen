#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 32000; i++) {
    for (int nl = 0; nl < 100000; nl++) {
        if (d[i] < (real_t)0.) {
            a[i] += b[i] * c[i];
        } else if (d[i] == (real_t)0.) {
            a[i] += b[i] * b[i];
        } else {
            a[i] += c[i] * c[i];
        }
    }
}
}
