#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int idx[4] = {0, 4, 8, 12};
for (i = 0; i < 4; ++i) {
    const int base = idx[i];
    const int dc = tmp[base] + 3;
    const int a0 = dc + tmp[base + 3];
    const int a1 = tmp[base + 1] + tmp[base + 2];
    const int a2 = tmp[base + 1] - tmp[base + 2];
    const int a3 = dc - tmp[base + 3];
}
}
