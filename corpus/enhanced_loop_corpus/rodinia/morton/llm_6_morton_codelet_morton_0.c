#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *x;
extern int *y;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_x = *x;
    int temp_y = *y;
    for (b = 0; b < 16; b++) {
        temp_x |= (i & (1 << (b * 2))) >> b;
        temp_y |= (i & (1 << (b * 2 + 1))) >> (b + 1);
    }
    *x = temp_x;
    *y = temp_y;
}
