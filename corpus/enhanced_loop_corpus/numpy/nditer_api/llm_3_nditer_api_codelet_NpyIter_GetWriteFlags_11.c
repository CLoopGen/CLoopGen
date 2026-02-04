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
    // Variant 2: Strided memory access with stride of 2, processing alternating elements in two passes
    int i;
    // First pass: even indices
    for (i = 0; i < nop; i += 2) {
        outwriteflags[i] = (op_itflags[i] & 1) != 0;
    }
    // Second pass: odd indices
    for (i = 1; i < nop; i += 2) {
        outwriteflags[i] = (op_itflags[i] & 1) != 0;
    }
}
