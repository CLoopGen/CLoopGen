#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *lens;
extern unsigned int codes;
extern unsigned int sym;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sym = 0; sym < codes && lens != NULL; sym++) {
        count[lens[sym]] += (lens[sym] < 16 && lens[sym] >= 0) ? 1 : 0;
    }
}
