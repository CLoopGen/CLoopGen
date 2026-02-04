#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i) {
    const int a0 = i * 2;
    const int a1 = i + 1;
    const int a2 = i * 3;
    const int a3 = i - 1;

    if (i % 2 == 0) {
        tmp[0 + i] = a0 + a1;
        tmp[8 + i] = a0 - a1;
    } else {
        tmp[0 + i] = a1;
        tmp[8 + i] = -a0;
    }

    if (i >= 2) {
        tmp[4 + i] = a3 + a2;
        tmp[12 + i] = a3 - a2;
    } else {
        tmp[4 + i] = a2;
        tmp[12 + i] = a3;
    }
}
}
