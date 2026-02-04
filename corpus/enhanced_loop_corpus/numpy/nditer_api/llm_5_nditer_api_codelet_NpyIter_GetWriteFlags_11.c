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
    char val;
    for (iop = 0; iop < nop; ++iop) {
        val = op_itflags[iop] & 1;
        if (val == 1) {
            outwriteflags[iop] = 1;
        } else {
            outwriteflags[iop] = 0;
        }
    }
}
