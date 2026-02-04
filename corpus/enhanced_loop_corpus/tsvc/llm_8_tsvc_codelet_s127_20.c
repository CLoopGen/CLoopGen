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
for (int nl = 0; nl < 4 * 100000; nl++) {
    j = -1;
    for (int i = 0; i < 32000 / 4; i++) {
        j++;
        a[j] = b[i] + c[i] * d[i] - e[i];
        j++;
        a[j] = b[i] + d[i] * e[i] + c[i];
        j++;
        a[j] = b[i+1] * c[i] + d[i];
        j++;
        a[j] = b[i+1] + d[i] * e[i] - c[i];
    }
}
}
