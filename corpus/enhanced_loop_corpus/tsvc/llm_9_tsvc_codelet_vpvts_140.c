#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    for (int i = 0; i < 16000; i++) {
        real_t temp1 = b[i] * s;
        real_t temp2 = b[31999 - i] * s;
        a[i] += temp1;
        a[31999 - i] += temp2;
        a[i] += temp2;
        a[31999 - i] += temp1;
    }
}
}
