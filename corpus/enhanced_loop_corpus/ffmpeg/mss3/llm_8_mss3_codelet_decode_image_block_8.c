#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int vec[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 4; i += 2) {
        vec[i] = 0;
        if (i + 1 < 4) vec[i + 1] = 0;
    }
}
