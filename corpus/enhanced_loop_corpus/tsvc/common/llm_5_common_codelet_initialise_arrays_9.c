#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32000; i++) {
        a[i] = 1 + i;
        if (i < 10000) {
            b[i] = 2 + i;
        } else if (i < 20000) {
            c[i] = 3 + i;
        } else {
            d[i] = 4 + i;
        }
        e[i] = 5 + i;
    }
}
