#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_2x11[121];
extern int x1;
extern int x2;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (x2 = 0; x2 < 11; x2++)
    for (x1 = 0; x1 < 11; x1++)
        mul_2x11[x1 + x2 * 11] = x1 + (x2 << 4);

}
