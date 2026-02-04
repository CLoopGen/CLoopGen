#include <stdio.h>

#include <inttypes.h>

extern char *PL_op_mask;
extern int PL_maxo;
extern char *bitmap;
extern int myopcode;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 4, processing every 4th element in multiple passes
    int stride = 4;
    int start;
    for (start = 0; start < stride; ++start) {
        int myopcode;
        for (myopcode = start; myopcode < PL_maxo; myopcode += stride) {
            if (PL_op_mask[myopcode])
                bitmap[myopcode >> 3] |= 1 << (myopcode & 7);
        }
    }
}
