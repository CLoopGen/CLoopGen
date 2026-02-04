#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        const int a0;
        const int a1;
        const int a2;
        const int a3;
        const int index = i * 4;
        tmp[index]      = a0 + a1;
        tmp[index + 1]  = a3 + a2;
        tmp[index + 3]  = a3 - a2;
        tmp[index + 2]  = a0 - a1;
    }
}
