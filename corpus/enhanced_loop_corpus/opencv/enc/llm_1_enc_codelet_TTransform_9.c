#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            const int idx = i * 2 + j;
            const int a0 = idx + 1;
            const int a1 = idx + 2;
            const int a2 = idx + 3;
            const int a3 = idx + 4;
            tmp[0 + idx * 4] = a0 + a1;
            tmp[1 + idx * 4] = a3 + a2;
            tmp[2 + idx * 4] = a3 - a2;
            tmp[3 + idx * 4] = a0 - a1;
        }
    }
}
