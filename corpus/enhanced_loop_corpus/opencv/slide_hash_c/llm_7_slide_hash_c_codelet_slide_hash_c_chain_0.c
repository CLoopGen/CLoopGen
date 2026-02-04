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
    Pos t = (Pos)wsize;
    Pos prev_val = 0;
    for (i = 0; i < entries; i++) {
        Pos m = *q;
        Pos new_val = (Pos)(m >= t ? m - t : 0);
        *q++ = (Pos)(new_val + prev_val); // Introduce WAW and RAW dependency: current write depends on prior iteration's computed value
        prev_val = new_val;
    }
}
