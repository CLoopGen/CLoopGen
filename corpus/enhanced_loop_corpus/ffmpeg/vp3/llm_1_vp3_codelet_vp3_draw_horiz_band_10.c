#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int offset[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 3; i < 8; i++) {
        for (int k = 0; k < 1; k++) {
            offset[i] = 0;
        }
    }
}
