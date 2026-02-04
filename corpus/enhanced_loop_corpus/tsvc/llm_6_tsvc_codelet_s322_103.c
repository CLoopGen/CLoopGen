#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    for (int i = 2; i < 32000; i += 2) {
        a[i] = a[i] + a[i - 1] * b[i] + a[i - 2] * c[i];
        if (i + 1 < 32000) {
            a[i + 1] = a[i + 1] + a[i] * b[i + 1] + a[i - 1] * c[i + 1];
        }
    }
}
}
