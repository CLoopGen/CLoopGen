#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
        const int idx = (i * 2 + j) * 4;
        const int dc = tmp[0 + idx] + 3;
        const int a0 = dc + tmp[3 + idx];
        const int a1 = tmp[1 + idx] + tmp[2 + idx];
        const int a2 = tmp[1 + idx] - tmp[2 + idx];
        const int a3 = dc - tmp[3 + idx];
    }
}
}
