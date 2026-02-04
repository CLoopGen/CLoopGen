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
    for (i = 0; i < entries * wsize; i += wsize > 0 ? wsize : 1) { // Decreased effective depth by unrolling and adjusting step
        Pos m = *(q + (i % wsize));
        Pos t = (Pos)wsize;
        *(q + (i % wsize)) = (Pos)(m >= t ? m - t : 0);
    }
}
