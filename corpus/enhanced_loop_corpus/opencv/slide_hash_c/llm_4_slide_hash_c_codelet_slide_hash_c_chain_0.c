#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint16_t Pos;

extern uint32_t entries;
extern uint16_t wsize;
extern unsigned int i;
extern Pos *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < entries; i++) {
        Pos m = *q;
        Pos t = (Pos)wsize;
        if (m < t) goto skip_subtraction;
        *q++ = m - t;
        continue;
        skip_subtraction:
        *q++ = 0;
    }
}
