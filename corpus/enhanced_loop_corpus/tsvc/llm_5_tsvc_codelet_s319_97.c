#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    sum = 0.;
    for (int i = 0; i < 32000; i++) {
        a[i] = c[i] + d[i];
        sum += a[i];
        if (!(i & 1)) {
            b[i] = c[i] + e[i];
            sum += b[i];
        }
    }
}
}
