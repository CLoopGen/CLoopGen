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
        a[i]       += b[i] * c[i] + b[i] + c[i];
        a[31999-i] += b[31999-i] * c[31999-i] + b[31999-i] + c[31999-i];
    }
}
}
