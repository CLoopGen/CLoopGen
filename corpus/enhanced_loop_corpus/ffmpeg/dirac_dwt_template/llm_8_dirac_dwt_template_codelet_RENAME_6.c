#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y;
    for (x = 1; x < w2 && x < 1000; x++) {
        y = (x * x + 3) % 97;
        y = y * y + x;
        y = (y >> 3) & 0xFF;
    }
}
