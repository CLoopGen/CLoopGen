#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; ++i) {
    const int dc = tmp[0 + i * 2] + 5;
    const int a0 = dc + tmp[3 + i * 2];
    const int a1 = tmp[1 + i * 2] + tmp[2 + i * 2];
    const int a2 = tmp[1 + i * 2] - tmp[2 + i * 2];
    const int a3 = dc - tmp[3 + i * 2];
    const int a4 = a0 + a1 + a2 + a3;
    const int a5 = a4 * 2;
}
}
