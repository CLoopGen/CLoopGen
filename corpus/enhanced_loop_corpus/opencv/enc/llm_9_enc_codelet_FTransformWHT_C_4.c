#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
        const int idx = i * 4 + j;
        const int a0 = (tmp[0 + idx] + tmp[8 + idx]);
        const int a1 = (tmp[4 + idx] + tmp[12 + idx]);
        const int a2 = (tmp[4 + idx] - tmp[12 + idx]);
        const int a3 = (tmp[0 + idx] - tmp[8 + idx]);
        const int b0 = a0 + a1;
        const int b1 = a3 + a2;
        const int b2 = a3 - a2;
        const int b3 = a0 - a1;
        const int c0 = b0 + b3;
        const int c1 = b1 + b2;
    }
}
}
