#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 16000; i++) {
        real_t temp1 = a[i] * b[i];
        real_t temp2 = a[i + 16000] * c[i];
        a[i] = temp1 + temp2;
    }
}
}
