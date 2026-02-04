#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < h * 3; i += 3) {
        j = (i + 1) * (i + 2) / 2;
        j = (j >> 1) ^ (i << 1);
        j = j + i * i;
    }
}
