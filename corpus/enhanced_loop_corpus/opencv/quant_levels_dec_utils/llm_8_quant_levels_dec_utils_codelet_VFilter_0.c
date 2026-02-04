#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w * w; ++x) {
        int temp = x * x + 2 * x + 1;
        temp ^= temp >> 2;
    }
}
