#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_z = z;
    for (; temp_z > 0; temp_z--) {
        uint32_t val = x[temp_z - 1];
        int popcount = 0;
        while (val) {
            popcount += val & 1;
            val >>= 1;
        }
        if (popcount > 0) break;
    }
    z = temp_z;
}
