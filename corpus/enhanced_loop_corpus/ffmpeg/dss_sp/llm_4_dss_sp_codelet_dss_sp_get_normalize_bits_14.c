#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int val;
extern int max_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (max_val = 0; val <= 16384; ++max_val) {
        val *= 2;
        if (val > 8192) {
            break;
        }
    }
}
