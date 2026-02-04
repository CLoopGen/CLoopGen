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
    for (i = 0; i < nsegs * 2; i += 2) {
        size += segments[i];
        if (i + 1 < nsegs) {
            size += segments[i + 1];
        }
    }
}
