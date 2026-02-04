#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint16_t *p = count; p <= &count[15]; p++)
        *p = 0;
}
