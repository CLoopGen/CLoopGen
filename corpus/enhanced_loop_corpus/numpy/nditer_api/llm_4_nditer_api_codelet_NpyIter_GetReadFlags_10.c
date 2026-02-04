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
    for (iop = 0; iop < nop; ++iop) {
        if (!(op_itflags[iop] & 2)) continue;
        outreadflags[iop] = 1;
    }
}
