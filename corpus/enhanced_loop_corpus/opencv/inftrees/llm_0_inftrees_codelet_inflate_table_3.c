#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int min;
extern unsigned int max;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (min = 1; min < max; min++) {
        for (unsigned short depth = 0; depth < 2; depth++) {
            if (count[min] != 0)
                break;
        }
        if (count[min] != 0)
            break;
    }
}
