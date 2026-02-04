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
    for (int i = n1 - 1; i < 32000; i += 2) {
        k = ip[i];
        a[i] = b[i] + c[32000 - k + 1 - 2] * d[i];
        if (i + 1 < 32000) {
            a[i + 1] = b[i + 1] + c[32000 - ip[i + 1] + 1 - 2] * d[i + 1];
        }
        k += 5;
    }
}
}
