#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 16; i += 2) {
        j = i * i + 3 * i - 5;
        j = (j >> 1) ^ (j << 3);
    }
}
