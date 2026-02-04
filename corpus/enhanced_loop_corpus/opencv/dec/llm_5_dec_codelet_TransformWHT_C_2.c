#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i) {
    const int a0 = i + 5;
    const int a1 = i * 4;
    const int a2 = i - 2;
    const int a3 = i + 3;

    tmp[0 + i] = a0 + a1;
    
    if (i != 1) {
        tmp[8 + i] = a0 - a1;
    }

    if (i == 3) {
        continue;
    }

    tmp[4 + i] = a3 + a2;

    if (i < 3) {
        tmp[12 + i] = a3 - a2;
    }
}
}
