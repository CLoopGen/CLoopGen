#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint16_t t;
extern uint16_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *ptr = l;
    for (i = 0; *(ptr + i) != t; i += 2)
        ;
}
