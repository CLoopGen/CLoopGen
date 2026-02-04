#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int npyiter_opitflags;

extern char *outreadflags;
extern int iop;
extern int nop;
extern npyiter_opitflags *op_itflags;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This accesses every second element in forward direction, then handles remainder
    int i;
    for (i = 0; i < nop; i += 2) {
        outreadflags[i] = (op_itflags[i] & 2) != 0;
    }
    // Handle odd-sized nop
    if (nop % 2 == 1) {
        outreadflags[nop - 1] = (op_itflags[nop - 1] & 2) != 0;
    }
}
