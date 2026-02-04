#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (max = 15; max >= 1; max--) {
        for (unsigned int depth = 0; depth < 2; depth++) {
            if (depth == 1 && count[max] != 0)
                break;
        }
        if (count[max] != 0)
            break;
    }
}
