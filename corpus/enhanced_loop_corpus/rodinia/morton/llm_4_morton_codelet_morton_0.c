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
for (b = 0; b < 16; b++) {
    if ((i & (1 << (b * 2))) != 0) {
        *x |= 1 << b;
    }
}
}
