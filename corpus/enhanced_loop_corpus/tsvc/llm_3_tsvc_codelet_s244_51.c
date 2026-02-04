#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000 - 1; ++i) {
        int j = 31999 - i; // Reverse access pattern: process arrays from end to start
        a[j] = b[j] + c[j] * d[j];
        b[j] = c[j] + b[j];
        if (j > 0) {
            a[j - 1] = b[j] + a[j - 1] * d[j];
        }
    }
}
}
