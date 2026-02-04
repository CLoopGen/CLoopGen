#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i) {
    const int idx = i * 4;
    const int a0 = (tmp[idx + 0] + tmp[idx + 3]);
    const int a1 = (tmp[idx + 1] + tmp[idx + 2]);
    const int a2 = (tmp[idx + 1] - tmp[idx + 2]);
    const int a3 = (tmp[idx + 0] - tmp[idx + 3]);
}
}
