#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 2) {
        // Introduce artificial loop-carried dependence via `s` across iterations
        s = b[i] + c[i];
        a[i] = s * e[i];
        b[i] = a[i] + d[i];

        // Second independent update without reusing `s`, breaking dependency chain
        s = b[i+1] + c[i+1];
        a[i+1] = s * e[i+1];
        b[i+1] = a[i+1] + d[i+1];
    }
}
}
