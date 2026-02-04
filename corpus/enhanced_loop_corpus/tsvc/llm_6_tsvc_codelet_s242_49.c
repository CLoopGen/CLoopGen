#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern real_t s1;
extern real_t s2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 5; nl++) {
    a[1] = b[1] + c[1] + d[1] + s1 + s2;
    for (int i = 2; i < 32000; ++i) {
        a[i] = a[i - 2] + s1 + s2 + b[i] + c[i] + d[i];
    }
}
}
