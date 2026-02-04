#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint16_t t;
extern uint16_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t mask = t ^ 0xFFFF;
    for (i = 0; (l[i] ^ t) != 0 && (l[i] | mask) == 0xFFFF; i++) {
        i += (l[i] > t) ? 2 : 1;
    }
}
