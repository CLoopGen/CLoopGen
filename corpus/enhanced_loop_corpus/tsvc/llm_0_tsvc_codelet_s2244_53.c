#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 100000; nl++) {
        a[0] = b[0] + c[0];
        for (int i = 1; i < 32000 - 1; i++) {
            a[i + 1] = b[i] + e[i];
            a[i] = b[i] + c[i];
        }
    }
}
