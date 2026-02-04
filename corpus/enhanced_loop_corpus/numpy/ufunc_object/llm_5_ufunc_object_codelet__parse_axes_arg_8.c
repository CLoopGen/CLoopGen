#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **remap_axis;
extern int nin;
extern int nop;
extern int iop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (iop = nin; iop < nop; iop++) {
    if (remap_axis[iop] != ((void *)0)) {
        continue;
    }
    remap_axis[iop] = ((void *)0);
}
}
