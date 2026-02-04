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
    real_t temp_a, temp_b, temp_c, temp_d, temp_e;
    for (int i = 0; i < 32000; i++) {
        temp_a = 1 + i;
        temp_b = 2 + i;
        temp_c = 3 + i;
        temp_d = 4 + i;
        temp_e = 5 + i;
        
        a[i] = temp_a;
        b[i] = temp_b;
        c[i] = temp_c;
        d[i] = temp_d;
        e[i] = temp_e;
    }
}
