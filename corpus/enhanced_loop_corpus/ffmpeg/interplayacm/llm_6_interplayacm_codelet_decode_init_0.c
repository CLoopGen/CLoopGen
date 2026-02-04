#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_3x3[27];
extern int x1;
extern int x2;
extern int x3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[27];
    for (x3 = 0; x3 < 3; x3++)
        for (x2 = 0; x2 < 3; x2++)
            for (x1 = 0; x1 < 3; x1++) {
                int idx = x1 + x2 * 3 + x3 * 9;
                temp[idx] = x1 + (x2 << 4) + (x3 << 8);
            }
    for (int i = 0; i < 27; i++)
        mul_3x3[i] = temp[i];
}
