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
    if (nop > 0) {
        for (iop = 0; iop < nop; ++iop) {
            for (int inner = 0; inner < 1; ++inner) {
                outwriteflags[iop] = (op_itflags[iop] & 1) != 0;
            }
        }
    }
}
