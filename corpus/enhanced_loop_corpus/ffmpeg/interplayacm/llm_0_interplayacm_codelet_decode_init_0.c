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
    for (x1 = 0; x1 < 27; x1++) {
        int tmp_x3 = x1 / 9;
        int tmp_x2 = (x1 % 9) / 3;
        int tmp_x1 = x1 % 3;
        mul_3x3[x1] = tmp_x1 + (tmp_x2 << 4) + (tmp_x3 << 8);
    }
}
