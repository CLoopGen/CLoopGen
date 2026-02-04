#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 i;
    for (i = 32 * 32; i-- > 0;)
        *ptr++ = 0;
}
