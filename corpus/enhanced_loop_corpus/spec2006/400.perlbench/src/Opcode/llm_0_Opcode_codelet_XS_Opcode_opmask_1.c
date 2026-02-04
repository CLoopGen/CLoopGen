#include <stdio.h>

#include <inttypes.h>

extern char *PL_op_mask;
extern int PL_maxo;
extern char *bitmap;
extern int myopcode;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; ++outer) {
    for (myopcode = 0; myopcode < PL_maxo; ++myopcode) {
        if (PL_op_mask[myopcode])
            bitmap[myopcode >> 3] |= 1 << (myopcode & 7);
    }
}
}
