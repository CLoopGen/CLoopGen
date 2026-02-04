#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int base = i * 4;
    const int a0 = i + 1;
    const int a1 = i + 2;
    const int a2 = i + 3;
    const int a3 = i + 4;
    tmp[base + 0] = a0 + a1;
    tmp[base + 1] = a3 + a2;
    tmp[base + 2] = tmp[base + 1] - a2; // WAR dependency introduced: write after read from tmp[base+1]
    tmp[base + 3] = tmp[base + 0] - a1; // WAW and RAW: depends on prior write to tmp[base+0]
}
}
