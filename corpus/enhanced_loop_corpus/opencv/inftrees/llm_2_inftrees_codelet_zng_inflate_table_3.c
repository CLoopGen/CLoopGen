#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int min;
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (min = 1; min < max; min += 2)
        if (min < 16 && count[min] != 0)  // bounds check added for safety
            break;
}
