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
    int temp = i & (3 << (b * 2));
    if (temp != 0) {
        *x |= (temp >> b) & 1;
        *y |= (temp >> (b + 1)) & 1;
    }
}
}
