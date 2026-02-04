#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_2x11[121];
extern int x1;
extern int x2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = 0;
    for (idx = 0; idx < 121; idx++) {
        int x2 = idx / 11;
        int x1 = idx % 11;
        mul_2x11[idx] = x1 + (x2 << 4);
    }
}
