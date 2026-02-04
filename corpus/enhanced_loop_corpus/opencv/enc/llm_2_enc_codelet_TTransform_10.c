#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int idx = i * 4;
    const int a0 = tmp[idx + 0] + tmp[idx + 8];
    const int a1 = tmp[idx + 1] + tmp[idx + 9];
    const int a2 = tmp[idx + 1] - tmp[idx + 9];
    const int a3 = tmp[idx + 0] - tmp[idx + 8];
    const int b0 = a0 + a1;
    const int b1 = a3 + a2;
    const int b2 = a3 - a2;
    const int b3 = a0 - a1;
}
}
