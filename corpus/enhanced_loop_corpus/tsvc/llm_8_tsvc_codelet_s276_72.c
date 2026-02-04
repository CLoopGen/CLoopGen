#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern int mid;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 2) {
        if (i + 1 < mid) {
            a[i] += b[i] * c[i] + d[i] * c[i];
            a[i+1] += b[i+1] * c[i+1] + d[i+1] * c[i+1];
        } else {
            a[i] += b[i] * d[i] - c[i] * d[i];
            a[i+1] += b[i+1] * d[i+1] - c[i+1] * d[i+1];
        }
    }
}
}
