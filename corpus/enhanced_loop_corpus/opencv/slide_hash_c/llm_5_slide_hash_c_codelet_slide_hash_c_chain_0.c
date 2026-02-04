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
        *q++ = (m >= t) ? (m - t) : ((m >= 0) ? 0 : 0);
    }
}
