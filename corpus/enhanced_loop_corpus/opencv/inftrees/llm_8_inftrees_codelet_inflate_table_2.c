#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (max = 15; max >= 1; max -= 2)
        if (count[max] != 0 && count[max - 1] == 0)
            break;
}
