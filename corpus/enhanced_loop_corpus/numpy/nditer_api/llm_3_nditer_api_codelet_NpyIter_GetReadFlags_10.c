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
    // Variant 2: Reverse consecutive memory access
    // Processes array from last to first element
    int iop;
    for (iop = nop - 1; iop >= 0; --iop) {
        outreadflags[iop] = (op_itflags[iop] & 2) != 0;
    }
}
