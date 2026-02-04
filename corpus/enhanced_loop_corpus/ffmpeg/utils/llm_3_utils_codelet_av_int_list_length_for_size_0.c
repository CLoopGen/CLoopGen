#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint8_t t;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    for (i = 0; l[i * stride] != t && (i * stride) < 256; i++)
        ;
}
