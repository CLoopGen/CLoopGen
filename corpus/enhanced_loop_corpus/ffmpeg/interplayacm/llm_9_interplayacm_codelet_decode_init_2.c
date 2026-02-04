#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_2x11[121];
extern int x1;
extern int x2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x2 = 0; x2 < 5; x2++)
    for (x1 = 0; x1 < 5; x1++) {
        int idx = x1 * 5 + x2;
        mul_2x11[idx] = (x1 << 3) + (x2 * x2) + 10;
    }

}
