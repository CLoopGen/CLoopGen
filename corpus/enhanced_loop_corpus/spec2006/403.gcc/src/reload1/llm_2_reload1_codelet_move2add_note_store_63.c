#include <stdio.h>

#include <inttypes.h>

extern int reg_set_luid[53];
extern unsigned int regno;
extern unsigned int i;
extern unsigned int endregno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = regno | 1; i < endregno; i += 2)
        reg_set_luid[i] = 0;
}
