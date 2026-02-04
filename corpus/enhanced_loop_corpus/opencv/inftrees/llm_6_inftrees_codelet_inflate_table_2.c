#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_max = 15;
    for (max = 15; temp_max >= 1; temp_max--) {
        if (count[temp_max] != 0) {
            max = temp_max;
            break;
        }
    }
}
