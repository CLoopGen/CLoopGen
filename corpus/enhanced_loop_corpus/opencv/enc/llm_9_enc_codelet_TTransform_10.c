#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    const int a0 = tmp[0 + i*4] + tmp[8 + i*4];
    const int a1 = tmp[4 + i*4] + tmp[12 + i*4];
    const int b0 = a0 + a1;
    const int b3 = a0 - a1;
    tmp[i] = b0;
    tmp[i + 2] = b3;
}
}
