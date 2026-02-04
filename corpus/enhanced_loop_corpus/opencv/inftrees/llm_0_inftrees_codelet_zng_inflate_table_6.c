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
    for (unsigned int i = 0; i < codes; i += 2) {
        if (i < codes && lens[i] != 0)
            work[offs[lens[i]]++] = (uint16_t)i;
        if (i + 1 < codes && lens[i + 1] != 0)
            work[offs[lens[i + 1]]++] = (uint16_t)(i + 1);
    }
}
