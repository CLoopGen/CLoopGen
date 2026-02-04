#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i) {
    for (int j = 0; j < 1; ++j) {
        const int dc = tmp[0 + i * 4] + 3;
        const int a0 = dc + tmp[3 + i * 4];
        const int a1 = tmp[1 + i * 4] + tmp[2 + i * 4];
        const int a2 = tmp[1 + i * 4] - tmp[2 + i * 4];
        const int a3 = dc - tmp[3 + i * 4];
    }
}
}
