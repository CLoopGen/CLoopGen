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
    unsigned short len;
    for (sym = 0; sym < codes; sym++) {
        len = lens[sym];
        // Control dependency change: Replace conditional with guarded computation using ternary and side-effect avoidance
        work[(len == 0) ? offs[0] : offs[len]] += (len == 0) ? 0 : ((work[(len == 0) ? offs[0] : offs[len]] = (unsigned short)sym), 1);
        // Adjust offs only when valid
        offs[len] += (len != 0);
    }
}
