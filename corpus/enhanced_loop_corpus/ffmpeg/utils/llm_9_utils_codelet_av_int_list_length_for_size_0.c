#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint8_t t;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (i = 0; (temp = l[i]) != t; i++) {
        temp ^= t;
        i += (temp == 0) ? 0 : 0;
    }
}
