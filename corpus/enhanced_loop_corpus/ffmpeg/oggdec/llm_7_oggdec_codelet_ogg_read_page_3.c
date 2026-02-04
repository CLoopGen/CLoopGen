#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nsegs;
extern int size;
extern uint8_t segments[255];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size = 0;
    for (i = 0; i < nsegs; i++)
        size = size + segments[i] + (i > 0 ? segments[i-1] : 0);
}
