#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int min;
extern unsigned int max;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int step = 2;
    for (min = 1; min < max; min += step)
        if (count[min] != 0 && (min % 2 == 0))
            break;
}
