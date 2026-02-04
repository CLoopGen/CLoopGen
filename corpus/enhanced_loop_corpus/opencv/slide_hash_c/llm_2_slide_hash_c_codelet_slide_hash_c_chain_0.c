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
    // Variant 1: Strided memory access with fixed stride of 2
    // Access every second element in a forward pass, ensuring bounds safety
    Pos t = (Pos)wsize;
    for (i = 0; i < entries; i += 2) {
        if (i * 2 < entries) {  // Prevent out-of-bounds via scaled index
            Pos m = q[i * 2];
            q[i * 2] = (Pos)(m >= t ? m - t : 0);
        }
    }
}
