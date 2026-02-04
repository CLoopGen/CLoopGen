#include <stdio.h>

#include <inttypes.h>

extern char *PL_op_mask;
extern int PL_maxo;
extern char *bitmap;
extern int myopcode;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (myopcode = 0; myopcode < PL_maxo; ++myopcode) {
    for (int unroll_factor = 0; unroll_factor < 1; ++unroll_factor) {
        if (PL_op_mask[myopcode])
            bitmap[myopcode >> 3] |= 1 << (myopcode & 7);
    }
}
}
