#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char reg_used_as_output[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 8; i <= 8 + 7; i += 2)
        if (!reg_used_as_output[i])
            break;
}
