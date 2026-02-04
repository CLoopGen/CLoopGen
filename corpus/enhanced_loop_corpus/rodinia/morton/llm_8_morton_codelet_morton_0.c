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
int temp_x = 0, temp_y = 0;
for (b = 0; b < 32; b += 2) {
    temp_x |= (i & (1 << b)) >> (b / 2);
    temp_y |= (i & (1 << (b + 1))) >> (b / 2 + 1);
}
*x = temp_x;
*y = temp_y;
}
