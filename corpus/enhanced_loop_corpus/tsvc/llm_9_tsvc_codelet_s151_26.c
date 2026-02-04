#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int i = 0; i < 16000 - 1; i++) {
        real_t temp1 = a[i + m] + b[i];
        real_t temp2 = a[i + m + 1] + b[i + 1];
        a[i] = temp1 * temp1;
        a[i + 16000] = temp2 * temp2;
    }
}
}
