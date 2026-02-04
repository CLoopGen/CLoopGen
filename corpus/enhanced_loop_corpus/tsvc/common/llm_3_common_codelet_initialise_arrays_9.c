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
    // Variant 2: Reverse Consecutive Memory Access (backward traversal)
    for (int i = 31999; i >= 0; i--) {
        a[i] = 1 + i;
        b[i] = 2 + i;
        c[i] = 3 + i;
        d[i] = 4 + i;
        e[i] = 5 + i;
    }
}
