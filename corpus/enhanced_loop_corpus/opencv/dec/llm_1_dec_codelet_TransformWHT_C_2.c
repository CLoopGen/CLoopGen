#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; ++outer) {
    for (i = 0; i < 2; ++i) {
        const int a0;
        const int a1;
        const int a2;
        const int a3;
        tmp[0 + outer * 2 + i] = a0 + a1;
        tmp[8 + outer * 2 + i] = a0 - a1;
        tmp[4 + outer * 2 + i] = a3 + a2;
        tmp[12 + outer * 2 + i] = a3 - a2;
    }
}
}
