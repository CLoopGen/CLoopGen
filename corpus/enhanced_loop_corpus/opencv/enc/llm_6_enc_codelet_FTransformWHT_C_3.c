#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int a0 = tmp[i * 4 + 0];
    const int a1 = tmp[i * 4 + 1];
    const int a2 = tmp[i * 4 + 2];
    const int a3 = tmp[i * 4 + 3];
    int sum01 = a0 + a1;
    int sum32 = a3 + a2;
    tmp[0 + i * 4] = sum01;
    tmp[1 + i * 4] = sum32;
    tmp[2 + i * 4] = a3 - a2;
    tmp[3 + i * 4] = a0 - a1;
}
}
