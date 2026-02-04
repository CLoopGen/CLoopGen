#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int offset = 4;
for (i = 0; i < 4; ++i) {
    const int a0 = i > 0 ? tmp[i-1] : 0;
    const int a1 = tmp[offset + i];
    const int a2 = tmp[2 * offset + i];
    const int a3 = tmp[3 * offset + i];
    tmp[i] = a0 + a1;
    tmp[offset + i] = a1 - a0;
    tmp[2 * offset + i] = a2 + a3;
    tmp[3 * offset + i] = a2 - a3;
}
}
