#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    for (int i = 1; i < 32000; i++) {
        int j = (i * 17) % 31999 + 1;
        a[j] += c[j] * d[j];
        b[j] = (j > 1 ? b[j - 1] : b[0]) + a[j] + d[j];
    }
}
}
