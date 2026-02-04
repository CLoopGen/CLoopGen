#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; ++i) {
    const int a0_0 = (tmp[0 + i*2] + tmp[12 + i*2]);
    const int a1_0 = (tmp[4 + i*2] + tmp[8 + i*2]);
    const int a2_0 = (tmp[4 + i*2] - tmp[8 + i*2]);
    const int a3_0 = (tmp[0 + i*2] - tmp[12 + i*2]);

    const int a0_1 = (tmp[1 + i*2] + tmp[13 + i*2]);
    const int a1_1 = (tmp[5 + i*2] + tmp[9 + i*2]);
    const int a2_1 = (tmp[5 + i*2] - tmp[9 + i*2]);
    const int a3_1 = (tmp[1 + i*2] - tmp[13 + i*2]);
}
}
