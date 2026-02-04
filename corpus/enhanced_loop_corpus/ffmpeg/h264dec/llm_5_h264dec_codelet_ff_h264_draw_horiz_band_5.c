#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 3; i < 8; i++) {
        if (i == 5) 
            continue;
        offset[i] = 0;
    }
}
