#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int inc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    for (int i = 0; i < 16000; i++) {
        real_t temp1 = b[i] * 1.5f;
        real_t temp2 = b[i + 16000] * 0.5f;
        a[i * inc] += temp1 - temp2;
    }
}
}
