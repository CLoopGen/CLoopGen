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
    if (nop > 0) {
        iop = 0;
        for (; iop < nop; ++iop) {
            outreadflags[iop] = (op_itflags[iop] & 2) != 0;
        }
    }
}
