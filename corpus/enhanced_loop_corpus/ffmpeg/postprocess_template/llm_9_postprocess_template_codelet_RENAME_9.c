#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 4; x++) {
    uint8_t *colsrc;
    int a, b;
    a = colsrc[0];
    b = (a * a) >> 15;
    for (y = 0; y < 2; y++) {
        int c;
        c = (b + y) & 0xFF;
        b = (b + c) >> 1;
    }
}
}
