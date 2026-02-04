#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    for (int i = 0; i < 16000; i++) {
        real_t prod = b[i] * c[i];
        a[i] += prod + prod * 0.5f;
        a[i] += prod * 0.25f;
        if (c[i] > b[i] && i % 100 == 0)
            break;
    }
}
}
