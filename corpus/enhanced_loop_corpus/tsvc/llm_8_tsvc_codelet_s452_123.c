#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 2) {
        a[i] = b[i] + c[i] * (real_t)(i + 1);
        if (i + 1 < 32000) {
            a[i + 1] = b[i + 1] + c[i + 1] * (real_t)(i + 2);
        }
    }
}
}
