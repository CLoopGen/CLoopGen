#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl += 2) {
    for (int i = 0; i < 16000; i++) {
        int j = 2 * i;
        a[j] = b[j] + c[i] * d[j];
        a[j+1] = b[j+1] + c[i] * d[j+1];
    }
}
}
