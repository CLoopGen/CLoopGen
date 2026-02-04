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
    unsigned int local_offs[16];
    for (unsigned int i = 0; i < 16; i++)
        local_offs[i] = offs[i];
    for (sym = 0; sym < codes; sym++) {
        unsigned short len = lens[sym];
        if (len != 0) {
            work[local_offs[len]] = (unsigned short)sym;
            local_offs[len]++;
        }
    }
    for (unsigned int i = 0; i < 16; i++)
        offs[i] = local_offs[i];
}
