#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned short *work;
extern unsigned int sym;
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sym = 0; sym < codes && codes > 0; sym += 2) {
        if (sym < codes && lens[sym] != 0) {
            unsigned short len = lens[sym];
            work[offs[len]++] = (unsigned short)sym;
        }
        if (sym + 1 < codes && lens[sym + 1] != 0) {
            unsigned short len = lens[sym + 1];
            work[offs[len]++] = (unsigned short)(sym + 1);
        }
    }
}
