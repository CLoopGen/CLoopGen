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
    for (int depth1 = 0; depth1 < 1; ++depth1) {
        for (iop = 0; iop < nop; ++iop) {
            outwriteflags[iop] = (op_itflags[iop] & 1) != 0;
        }
    }
}
