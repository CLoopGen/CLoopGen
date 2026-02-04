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
    for (sym = 0; sym < codes && codes > 0; sym += 2) {
        if (lens[sym] < 16)
            count[lens[sym]]++;
        if (sym + 1 < codes && lens[sym + 1] < 16)
            count[lens[sym + 1]]++;
    }
}
