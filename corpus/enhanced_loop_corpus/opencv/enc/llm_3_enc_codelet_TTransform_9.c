#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[4][4] = {
        {0, 4, 8, 12},
        {1, 5, 9, 13},
        {2, 6, 10, 14},
        {3, 7, 11, 15}
    };
    for (i = 0; i < 4; i++) {
        const int a0;
        const int a1;
        const int a2;
        const int a3;
        tmp[indices[0][i]] = a0 + a1;
        tmp[indices[1][i]] = a3 + a2;
        tmp[indices[2][i]] = a3 - a2;
        tmp[indices[3][i]] = a0 - a1;
    }
}
