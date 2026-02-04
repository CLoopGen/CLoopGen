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
    // Reorder computations to access tab elements in increasing order where possible,
    // reducing stride and improving cache locality. xp is still incremented by 2 per iteration.
    for (i = 0; i < 4; i++) {
        int idx = i * 4;
        int rev_idx1 = 30 - idx;  // 30, 26, 22, 18
        int rev_idx2 = 28 - idx;  // 28, 24, 20, 16
        int rev_idx3 = 31 - idx;  // 31, 27, 23, 19
        int rev_idx4 = 29 - idx;  // 29, 25, 21, 17

        // Process in an order that groups lower indices first
        xr = (((int64_t)tab[idx] * (int64_t)xp[0]) >> 15);
        tab[rev_idx1] = tab[idx] - xr;
        tab[idx] = tab[idx] + xr;

        xr = (((int64_t)tab[idx + 1] * (int64_t)xp[0]) >> 15);
        tab[rev_idx3] = tab[idx + 1] - xr;
        tab[idx + 1] = tab[idx + 1] + xr;

        xr = (((int64_t)tab[idx + 2] * (int64_t)xp[1]) >> 15);
        tab[rev_idx2] = tab[idx + 2] - xr;
        tab[idx + 2] = tab[idx + 2] + xr;

        xr = (((int64_t)tab[idx + 3] * (int64_t)xp[1]) >> 15);
        tab[rev_idx4] = tab[idx + 3] - xr;
        tab[idx + 3] = tab[idx + 3] + xr;

        xp += 2;
    }
}
