#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern int *restrict ip;
extern int n1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int j = 0; j < 32000 - (n1 - 1); j++) {
        int i = n1 - 1 + j;
        k = ip[i];
        int idx_c = (k * 7) % 32000;
        a[i] = b[i] + c[idx_c] * d[i];
        k += 5;
    }
}
}
