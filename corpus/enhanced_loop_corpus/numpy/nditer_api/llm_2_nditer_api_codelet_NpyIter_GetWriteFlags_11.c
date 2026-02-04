#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int npyiter_opitflags;

extern char *outwriteflags;
extern int iop;
extern int nop;
extern npyiter_opitflags *op_itflags;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling by 2 for improved spatial locality and reduced loop overhead
    int i;
    for (i = 0; i < nop - 1; i += 2) {
        outwriteflags[i]     = (op_itflags[i]     & 1) != 0;
        outwriteflags[i + 1] = (op_itflags[i + 1] & 1) != 0;
    }
    // Handle remaining element if nop is odd
    if (i < nop) {
        outwriteflags[i] = (op_itflags[i] & 1) != 0;
    }
}
