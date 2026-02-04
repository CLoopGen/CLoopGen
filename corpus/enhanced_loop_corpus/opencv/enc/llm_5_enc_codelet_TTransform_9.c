#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i += 2) {
        const int a0 = (i + 0) * 5;
        const int a1 = (i + 1) * 3;
        const int a2 = (i + 0) * 2;
        const int a3 = (i + 1) * 4;
        tmp[0 + i * 4] = a0 + a1;
        if (i + 1 < 4) {
            tmp[1 + i * 4] = a3 + a2;
            tmp[2 + i * 4] = a3 - a2;
            tmp[3 + i * 4] = a0 - a1;
        }
    }
}
