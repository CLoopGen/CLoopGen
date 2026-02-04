#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    j = -1;
    for (int i = 0; i < 16000; i++) {
        real_t term1 = d[i] * e[i];
        real_t term2 = d[i + 16000] * e[i + 16000];
        if (b[i] > (real_t)0.) {
            j++;
            a[j] = b[i] + term1 + term2;
        } else {
            j++;
            a[j] = c[i] + term1 + term2;
        }
    }
}
}
