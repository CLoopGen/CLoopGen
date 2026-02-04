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
for (i = 0; i < nsegs; i++) {
    for (int k = 0; k < 1; k++)
        size += segments[i];
}
}
