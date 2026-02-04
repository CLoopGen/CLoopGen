#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        offset[i] = i * i + 2;
        if (i + 1 < 8)
            offset[i + 1] = (i + 1) * (i + 1) + 2;
    }
}
