#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int val;
extern int max_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_val = val;
    for (max_val = 0; local_val <= 16384; ++max_val)
        local_val *= 2;
    val = local_val;
}
