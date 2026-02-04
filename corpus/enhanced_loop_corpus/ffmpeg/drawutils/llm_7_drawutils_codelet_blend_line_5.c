#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dx;
extern int w;
extern unsigned int asrc;
extern unsigned int tau;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_val;
    for (x = 0; x < w; x++) {
        local_val = (*dst * tau + asrc) >> 24;
        *(dst + dx) = local_val;  // Write to next location instead of current
        dst += dx;
    }
    // Removes write-after-write (WAW) on same memory location by writing to offset
    // Introduces WAR hazard potential via overlapping reads/writes at adjacent locations
    // Modifies data flow: value computed from current, written to next
}
