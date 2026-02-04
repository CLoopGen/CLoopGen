#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        const int a0 = i * 2;
        const int a1 = i + 1;
        const int a2 = i - 1;
        const int a3 = i * 3;
        tmp[0 + i * 2] = a0 + a1 + a2;
        tmp[1 + i * 2] = a3 + a2 - a1;
        tmp[2 + i * 2] = a3 - a2 + a0;
        tmp[3 + i * 2] = a0 - a1 - a3;
    }
}
