#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char indices5[16];
extern unsigned char indices7[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char access_pattern[16] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0}; // Reverse access order
    for (i = 0; i < 16; i++) {
        unsigned char index;
        index = indices7[access_pattern[i]];
        if (index == 0)
            indices5[access_pattern[i]] = 1;
        else if (index == 1)
            indices5[access_pattern[i]] = 0;
        else
            indices5[access_pattern[i]] = 9 - index;
    }
}
