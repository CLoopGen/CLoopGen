#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_2x11[121];
extern int x1;
extern int x2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[121];
    for (x2 = 0; x2 < 11; x2++)
        for (x1 = 0; x1 < 11; x1++)
            temp[x1 + x2 * 11] = x1 + (x2 << 4);
    for (int i = 0; i < 121; i++)
        mul_2x11[i] = temp[i];
}
