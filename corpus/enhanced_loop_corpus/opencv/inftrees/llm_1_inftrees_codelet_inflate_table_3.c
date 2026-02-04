#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int min;
extern unsigned int max;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int outer = 1;
    for (; outer < max; outer++) {
        min = outer;
        if (count[min] != 0)
            break;
    }
}
