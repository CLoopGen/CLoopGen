#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int stride = 4;
for (i = 0; i < 4; ++i) {
    const int base[4] = {0, 4, 8, 12};
    const int offset = i;
    const int a0 = (tmp[base[0] + offset] + tmp[base[3] + offset]);
    const int a1 = (tmp[base[1] + offset] + tmp[base[2] + offset]);
    const int a2 = (tmp[base[1] + offset] - tmp[base[2] + offset]);
    const int a3 = (tmp[base[0] + offset] - tmp[base[3] + offset]);
}
}
