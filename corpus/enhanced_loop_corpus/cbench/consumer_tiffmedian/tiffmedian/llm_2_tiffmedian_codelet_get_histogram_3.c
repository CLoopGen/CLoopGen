#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 size = (1L << 5) * (1L << 5) * (1L << 5);
    for (i = size; i-- > 0;)
        ptr[i] = 0;
}
