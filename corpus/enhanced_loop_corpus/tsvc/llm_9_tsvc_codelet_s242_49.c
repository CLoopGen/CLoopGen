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
for (int nl = 0; nl < 100000 / 10; nl++) {
    for (int i = 1; i < 16000; ++i) {
        a[i] = (a[i - 1] + s1 + b[i]) * 0.5f;
        a[i + 16000] = (a[i + 15999] + s2 + c[i] + d[i]) * 0.5f;
    }
}
}
