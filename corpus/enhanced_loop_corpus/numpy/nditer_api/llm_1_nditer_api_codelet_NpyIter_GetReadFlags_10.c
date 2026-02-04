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
    int inner;
    for (iop = 0; iop < nop; ++iop) {
        for (inner = 0; inner < 1; ++inner) {
            outreadflags[iop] = (op_itflags[iop] & 2) != 0;
        }
    }
}
