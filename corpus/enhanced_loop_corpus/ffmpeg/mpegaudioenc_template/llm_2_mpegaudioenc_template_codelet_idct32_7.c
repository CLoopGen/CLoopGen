#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int i;
extern int xr;
extern  int *xp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize array accesses to use consecutive indices where possible.
    // We precompute base indices and access tab in a more sequential manner.
    int *base = tab;
    for (i = 0; i < 4; i++) {
        int idx1 = i * 4;
        int idx2 = 30 - i * 4;
        int idx3 = 2 + i * 4;
        int idx4 = 28 - i * 4;
        int idx5 = 31 - i * 4;
        int idx6 = 1 + i * 4;
        int idx7 = 3 + i * 4;
        int idx8 = 29 - i * 4;

        xr = (((int64_t)(base[idx2]) * (int64_t)(xp[0])) >> 15);
        base[idx2] = (base[idx1] - xr);
        base[idx1] = (base[idx1] + xr);

        xr = (((int64_t)(base[idx3]) * (int64_t)(xp[1])) >> 15);
        base[idx3] = (base[idx4] - xr);
        base[idx4] = (base[idx4] + xr);

        xr = (((int64_t)(base[idx5]) * (int64_t)(xp[0])) >> 15);
        base[idx5] = (base[idx6] - xr);
        base[idx6] = (base[idx6] + xr);

        xr = (((int64_t)(base[idx7]) * (int64_t)(xp[1])) >> 15);
        base[idx7] = (base[idx8] - xr);
        base[idx8] = (base[idx8] + xr);

        xp += 2;
    }
}
