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
    for (b = 0; b < 8; b += 2) {
        *x |= (i & (1 << (b * 2))) >> b;
        *y |= (i & (1 << (b * 2 + 1))) >> (b + 1);
        b++;
        if (b < 16) {
            *x |= (i & (1 << (b * 2))) >> b;
            *y |= (i & (1 << (b * 2 + 1))) >> (b + 1);
        }
    }
}
