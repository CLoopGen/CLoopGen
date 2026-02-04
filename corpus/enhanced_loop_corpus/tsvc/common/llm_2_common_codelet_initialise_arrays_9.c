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
    // Variant 1: Strided Memory Access (stride of 4)
    for (int i = 0; i < 32000; i += 4) {
        a[i] = 1 + i;
        b[i] = 2 + i;
        c[i] = 3 + i;
        d[i] = 4 + i;
        e[i] = 5 + i;
        
        if (i + 1 < 32000) {
            a[i+1] = 1 + (i+1);
            b[i+1] = 2 + (i+1);
            c[i+1] = 3 + (i+1);
            d[i+1] = 4 + (i+1);
            e[i+1] = 5 + (i+1);
        }
        if (i + 2 < 32000) {
            a[i+2] = 1 + (i+2);
            b[i+2] = 2 + (i+2);
            c[i+2] = 3 + (i+2);
            d[i+2] = 4 + (i+2);
            e[i+2] = 5 + (i+2);
        }
        if (i + 3 < 32000) {
            a[i+3] = 1 + (i+3);
            b[i+3] = 2 + (i+3);
            c[i+3] = 3 + (i+3);
            d[i+3] = 4 + (i+3);
            e[i+3] = 5 + (i+3);
        }
    }
}
