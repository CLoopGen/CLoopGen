#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int offset[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 16; i += 2)
        offset[i % 8] = i * i + 2 * i + 1;
}
