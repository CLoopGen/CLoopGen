#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offsets[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = -8;
    for (i = 0; i < 8; i++) {
        offsets[i] = base + i;
    }
}
