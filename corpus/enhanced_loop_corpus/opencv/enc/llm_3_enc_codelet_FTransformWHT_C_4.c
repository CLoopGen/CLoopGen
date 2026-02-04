#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int indices[4][4] = {{0, 8, 4, 12}, {1, 9, 5, 13}, {2, 10, 6, 14}, {3, 11, 7, 15}};
for (i = 0; i < 4; ++i) {
    const int* idx = indices[i];
    const int a0 = (tmp[idx[0]] + tmp[idx[1]]);
    const int a1 = (tmp[idx[2]] + tmp[idx[3]]);
    const int a2 = (tmp[idx[2]] - tmp[idx[3]]);
    const int a3 = (tmp[idx[0]] - tmp[idx[1]]);
    const int b0 = a0 + a1;
    const int b1 = a3 + a2;
    const int b2 = a3 - a2;
    const int b3 = a0 - a1;
}
}
