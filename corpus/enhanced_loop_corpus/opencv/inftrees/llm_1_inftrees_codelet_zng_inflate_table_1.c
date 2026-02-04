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
    if (codes > 0) {
        sym = 0;
        for (; sym < codes; ) {
            count[lens[sym]]++;
            sym++;
        }
    }
}
