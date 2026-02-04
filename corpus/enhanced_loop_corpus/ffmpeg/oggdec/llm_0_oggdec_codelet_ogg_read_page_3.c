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
int j;
for (j = 0; j < nsegs; j++) {
    for (i = 0; i <= j; i++)
        size += segments[i];
}
}
