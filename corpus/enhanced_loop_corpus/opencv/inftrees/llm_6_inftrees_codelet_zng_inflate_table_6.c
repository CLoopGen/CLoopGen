#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *lens;
extern unsigned int codes;
extern uint16_t *work;
extern unsigned int sym;
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_sym;
    for (sym = 0; sym < codes; sym++) {
        if (lens[sym] != 0) {
            temp_sym = (uint16_t)sym;
            work[offs[lens[sym]]] = temp_sym;
            offs[lens[sym]]++;
        }
    }
}
