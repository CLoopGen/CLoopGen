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
    for (sym = 0; sym < codes && codes > 0; sym += 2) {
        if (sym < codes && lens[sym] != 0) {
            uint16_t len_val = lens[sym];
            work[offs[len_val]++] = (uint16_t)sym;
        }
        if (sym + 1 < codes && lens[sym + 1] != 0) {
            uint16_t len_val = lens[sym + 1];
            work[offs[len_val]++] = (uint16_t)(sym + 1);
        }
    }
}
