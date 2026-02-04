#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int i = 0; i < 32000 - 1; i++) {
        a[i] = b[i] * c[i] * d[i];
        if (!(a[i] < 1e-6f)) {
            b[i] = a[i] * a[i + 1] * d[i];
        }
    }
}
}
