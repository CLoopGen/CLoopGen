#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_count;
    for (max = 15; max >= 1; max--) {
        temp_count = count[max];
        if (temp_count != 0) {
            temp_count--;
            if (temp_count == 0)
                break;
        }
    }
}
