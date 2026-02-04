#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 1; ++i) {
    for (int j = 0; j < 4; ++j) {
        const int a0 = (tmp[0 + j] + tmp[12 + j]);
        const int a1 = (tmp[4 + j] + tmp[8 + j]);
        const int a2 = (tmp[4 + j] - tmp[8 + j]);
        const int a3 = (tmp[0 + j] - tmp[12 + j]);
    }
}
}
