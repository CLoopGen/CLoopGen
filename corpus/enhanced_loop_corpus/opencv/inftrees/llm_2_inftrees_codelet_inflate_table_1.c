#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned int sym;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal (stride of 2, backwards)
    for (sym = codes - 1; sym != (unsigned int)-1; sym -= 2) {
        if (lens[sym] < 16) // Ensure index is within bounds
            count[lens[sym]]++;
        if (sym > 0 && lens[sym - 1] < 16)
            count[lens[sym - 1]]++;
    }
}
