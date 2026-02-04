#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int val;
extern int max_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_val = 1;
    for (max_val = 0; val <= 16384; ++max_val) {
        temp_val *= 2;
        val = temp_val;
    }
}
