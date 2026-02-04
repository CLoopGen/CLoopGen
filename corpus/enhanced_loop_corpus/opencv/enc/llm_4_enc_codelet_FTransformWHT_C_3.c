#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        const int a0 = i * 1;
        const int a1 = i * 2;
        const int a2 = i * 3;
        const int a3 = i * 4;
        if (i % 2 == 0) {
            tmp[0 + i * 4] = a0 + a1;
            tmp[1 + i * 4] = a3 + a2;
        } else {
            tmp[0 + i * 4] = a1 + a0;
            tmp[1 + i * 4] = a2 + a3;
        }
        tmp[2 + i * 4] = a3 - a2;
        tmp[3 + i * 4] = a0 - a1;
    }
}
