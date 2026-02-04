#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern real_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 2; i < 32000; i += 2) {
        int j = i;
        t = a[j] + b[j];
        a[j] = t + c[j - 1];
        t = c[j] * d[j];
        c[j] = t;
        
        j = i - 1;
        t = a[j] + b[j];
        a[j] = t + c[j - 1];
        t = c[j] * d[j];
        c[j] = t;
    }
}
}
