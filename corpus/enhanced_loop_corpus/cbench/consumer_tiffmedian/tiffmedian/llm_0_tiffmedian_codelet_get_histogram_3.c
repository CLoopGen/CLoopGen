#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 outer, inner;
    for (outer = 32; outer > 0; outer--)
        for (inner = 32; inner > 0; inner--)
            *ptr++ = 0;
}
