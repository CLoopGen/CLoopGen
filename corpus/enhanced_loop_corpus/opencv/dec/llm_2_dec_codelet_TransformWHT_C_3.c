#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i) {
    const int dc = tmp[i] + 3;
    const int a0 = dc + tmp[i + 12];
    const int a1 = tmp[i + 4] + tmp[i + 8];
    const int a2 = tmp[i + 4] - tmp[i + 8];
    const int a3 = dc - tmp[i + 12];
}
}
