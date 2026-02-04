#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 10; i += 2)
        offset[i % 8] = i * i + 2 * i + 1;
}
