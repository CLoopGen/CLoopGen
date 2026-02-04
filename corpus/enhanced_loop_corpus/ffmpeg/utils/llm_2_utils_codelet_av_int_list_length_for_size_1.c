#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint16_t t;
extern uint16_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; l[i << 1] != t && (i << 1) < UINT16_MAX; i++)
        ;
}
