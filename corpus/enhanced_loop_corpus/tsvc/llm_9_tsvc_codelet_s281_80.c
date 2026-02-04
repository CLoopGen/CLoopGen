#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl += 2) {
    for (int i = 0; i < 16000; i++) {
        real_t idx1 = a[32000 - i - 1] + b[i] * c[i];
        real_t idx2 = a[32000 - (i + 16000) - 1] + b[i + 16000] * c[i + 16000];
        x = (idx1 + idx2) * (real_t)0.5;
        a[i] = idx1 - (real_t)1.5;
        a[i + 16000] = idx2 - (real_t)1.5;
        b[i] = idx1;
        b[i + 16000] = idx2;
    }
}
}
